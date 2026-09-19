/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:29:05 by ozamora-          #+#    #+#             */
/*   Updated: 2026/09/18 20:30:32 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "colors.hpp"

#include <algorithm> // For std::lower_bound()
#include <climits> // For INT_MAX
#include <cstdlib> // For std::strtol()
#include <iostream> // For std::cout, std::endl
#include <stdexcept> // For std::exception, std::invalid_argument

// Used for helper functions
#include <ctime>   // For std::clock()
#include <iomanip> // For std::setprecision(), std::fixed,

/*
 * Debug macro: activate by defining DEBUG during compilation
 * When DEBUG is defined, DBG_MSG(x) will print trace messages;
 * in normal compilation DBG_MSG is a no-op.
 * Example: 
 * - make debug 
 * - make -C ex00 debug
 */

#ifdef DEBUG
 # define DBG_MSG(x) std::cout << "PmergeMe " << x << std::endl
#else
 # define DBG_MSG(x) ((void)0)
#endif

template <typename Container>
PmergeMe<Container>::PmergeMe(void) : _values() {
	DBG_MSG("Default Constructor called");
}

template <typename Container>
PmergeMe<Container>::PmergeMe(int argc, char **argv) : _values() {
	DBG_MSG("Parameterized Constructor called");
	parse(argc, argv);
	if (_values.empty())
		throw std::invalid_argument(RED "Error: " RESET "no numbers provided");
}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& src) : _values(src._values) {
	DBG_MSG("Copy Constructor called");
}

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe& src) {
	DBG_MSG("Copy Assignment Operator called");
	if (this != &src)
		_values = src._values;
	return *this;
}

template <typename Container>
PmergeMe<Container>::~PmergeMe(void) {
	DBG_MSG("Destructor called");
}

// Private member functions

template <typename Container>
void PmergeMe<Container>::parse(int argc, char **argv)
{
	long	number;
	char*	endPtr;

	for(int i = 1; i < argc; i++)
	{
		number = std::strtol(argv[i], &endPtr, 10);
		if (*endPtr != '\0' || number < 0 || number > INT_MAX)
			throw std::invalid_argument(RED "Error: " RESET "invalid positive integer");
		_values.push_back(static_cast<int>(number));
	}
}

template <typename Container>
void PmergeMe<Container>::createPairs(typename Container::const_iterator first, typename Container::const_iterator last, std::vector<std::pair<int, int> >& pairs) const
{
	// Ford-Johnson starts by comparing disjoint pairs. The larger value is
	// the pair's winner; the smaller value waits in the pending chain.
	while (first != last)
	{
		int firstValue = *first++;
		int secondValue = *first++;
		if (firstValue < secondValue)
			std::swap(firstValue, secondValue);
		pairs.push_back(std::make_pair(firstValue, secondValue));
	}
}

template <typename Container>
void PmergeMe<Container>::sortPairs(std::vector<std::pair<int, int> >& pairs) const
{
	if (pairs.size() <= 1)
		return;

	std::vector<std::pair<int, int> > left;
	std::vector<std::pair<int, int> > right;

	typedef std::vector<std::pair<int, int> >::iterator Iterator;
	Iterator middle = pairs.begin();

	std::advance(middle, pairs.size() / 2); // Move middle iterator to the midpoint of the pairs vector
	left.insert(left.end(), pairs.begin(), middle); // Copy first half to left
	right.insert(right.end(), middle, pairs.end()); // Copy second half to right

	// This is the recursive Ford-Johnson phase: sort the winners while
	// carrying each pair's pending value along with its winner.
	sortPairs(left);
	sortPairs(right);

	// Merge the winner-sorted halves back into the original pairs vector.
	Iterator leftIt = left.begin();
	Iterator rightIt = right.begin();
	Iterator output = pairs.begin();
	while (leftIt != left.end() && rightIt != right.end())
	{
		if (leftIt->first <= rightIt->first)
		{
			*output = *leftIt;
			++output;
			++leftIt;
		}
		else
		{
			*output = *rightIt;
			++output;
			++rightIt;
		}
	}
	while (leftIt != left.end())
	{
		*output = *leftIt;
		++output;
		++leftIt;
	}
	while (rightIt != right.end())
	{
		*output = *rightIt;
		++output;
		++rightIt;
	}
}

template <typename Container>
void PmergeMe<Container>::splitPairs(const std::vector<std::pair<int, int> >& pairs, Container& mainChain, Container& pending) const
{
	typedef std::vector<std::pair<int, int> >::const_iterator Iterator;
	for (Iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		mainChain.push_back(it->first);
		pending.push_back(it->second);
	}
}

template <typename Container>
void PmergeMe<Container>::insertPending(Container& mainChain, const Container& pending) const
{
	if (pending.empty())
		return;

	// The first pending value is bounded by the first winner, so it can be
	// inserted immediately. The remaining values use binary insertion.
	mainChain.insert(mainChain.begin(), pending.front());

	// Ford-Johnson inserts pending values in reverse Jacobsthal-group order.
	// The boundaries 1, 3, 5, 11, 21, 43... are generated as needed; the last
	// boundary is clipped to pending.size(), so no sequence needs to be stored.
	size_t previous = 1;
	size_t current = 3;
	while (previous < pending.size())
	{
		size_t upper = std::min(current, pending.size());
		for (size_t index = upper; index > previous; --index)
		{
			typedef typename Container::const_iterator ConstIterator;
			ConstIterator value = pending.begin();
			std::advance(value, index - 1);
			typedef typename Container::iterator Iterator;
			Iterator position = std::lower_bound(mainChain.begin(), mainChain.end(), *value);
			mainChain.insert(position, *value);
		}
		current = current + 2 * previous; // Jacobsthal sequence: J(n) = J(n-1) + 2*J(n-2)
		previous = upper;
	}
}

template <typename Container>
void PmergeMe<Container>::sortRange(Container& values) const
{
	if (values.size() <= 1)
		return;

	std::vector<std::pair<int, int> > pairs;
	Container mainChain;
	Container pending;

	bool hasStraggler = values.size() % 2 != 0;
	int straggler = 0;
	typename Container::const_iterator end = values.end();
	if (hasStraggler)
	{
		--end;
		straggler = *end;
	}

	createPairs(values.begin(), end, pairs);
	sortPairs(pairs);
	splitPairs(pairs, mainChain, pending);
	insertPending(mainChain, pending);

	if (hasStraggler)
	{
		typename Container::iterator position = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(position, straggler);
	}
	values = mainChain;
}

// Public member functions

template <typename Container>
Container PmergeMe<Container>::sort()
{
	sortRange(_values);
	return _values;
}

template <typename Container>
Container PmergeMe<Container>::getValues() const
{
	return _values;
}

template <typename Container>
bool PmergeMe<Container>::isSorted() const
{
	if (_values.size() < 2)
		return true;
	typedef typename Container::const_iterator Iterator;
	Iterator current = _values.begin();
	Iterator next = current;
	++next;
	while (next != _values.end())
	{
		if (*next < *current)
			return false;
		++current;
		++next;
	}
	return true;
}

// Helper functions, not part of the PmergeMe class

template <typename Container>
void printRange(const Container& values)
{
	typedef typename Container::const_iterator Iterator;
	for (Iterator it = values.begin(); it != values.end(); ++it)
	{
		if (std::distance(values.begin(), it) >= MAX_PRINT_SIZE)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

template <typename Container>
double timeSort(PmergeMe<Container>& sorter, Container& before, Container& after)
{
	before = sorter.getValues();
	std::clock_t start = std::clock(); // Start timing in microseconds
	after = sorter.sort();
	std::clock_t end = std::clock();
	return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0; // Return the time in microseconds
}
