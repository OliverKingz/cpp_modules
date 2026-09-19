/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 00:00:00 by ozamora-          #+#    #+#             */
/*   Updated: 2026/09/19 13:28:37 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "colors.hpp"

#include <algorithm> // For std::lower_bound()
#include <climits> // For INT_MAX
#include <cstdlib> // For std::strtol()
#include <ctime> // For std::clock()
#include <iostream> // For std::cout, std::endl
#include <stdexcept> // For std::exception, std::invalid_argument

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

PmergeMe::PmergeMe(void) : _vector(), _list() {
	DBG_MSG("Default Constructor called");
}

PmergeMe::PmergeMe(int argc, char **argv) : _vector(), _list() {
	DBG_MSG("Parameterized Constructor called");
	parse(argc, argv);
	if (_vector.empty())
		throw std::invalid_argument(RED "Error: " RESET "no numbers provided");
}

PmergeMe::PmergeMe(const PmergeMe& src) : _vector(src._vector), _list(src._list) {
	DBG_MSG("Copy Constructor called");
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
	DBG_MSG("Copy Assignment Operator called");
	if (this != &src)
	{
		_vector = src._vector;
		_list = src._list;
	}
	return *this;
}

PmergeMe::~PmergeMe(void) {
	DBG_MSG("Destructor called");
}

// Private member functions

void PmergeMe::parse(int argc, char **argv) {
	for (int index = 1; index < argc; ++index)
	{
		char *endPtr;
		long number = std::strtol(argv[index], &endPtr, 10);
		if (*endPtr != '\0' || number < 0 || number > INT_MAX)
			throw std::invalid_argument(RED "Error: " RESET "invalid positive integer");
		_vector.push_back(static_cast<int>(number));
		_list.push_back(static_cast<int>(number));
	}
}

void PmergeMe::sortVectorPairs(std::vector<std::pair<int, int> >& pairs) const {
	// Base case: if the vector of pairs has 0 or 1 element, it's already sorted
	if (pairs.size() <= 1)
		return;

	std::vector<std::pair<int, int> > left;
	std::vector<std::pair<int, int> > right;
	std::vector<std::pair<int, int> >::iterator middle = pairs.begin();

	std::advance(middle, pairs.size() / 2); // Move middle iterator to the midpoint of the pairs vector
	left.insert(left.end(), pairs.begin(), middle); // Copy first half to left
	right.insert(right.end(), middle, pairs.end()); // Copy second half to right

	// This is the recursive Ford-Johnson phase: sort the winners while carrying each pair's pending value
	// along with its winner.
	sortVectorPairs(left);
	sortVectorPairs(right);

	// Merge the winner-sorted halves back into the original pairs vector.
	std::vector<std::pair<int, int> >::iterator leftIt = left.begin();
	std::vector<std::pair<int, int> >::iterator rightIt = right.begin();
	std::vector<std::pair<int, int> >::iterator output = pairs.begin();
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

void PmergeMe::sortListPairs(std::list<std::pair<int, int> >& pairs) const {
	// Base case: if the vector of pairs has 0 or 1 element, it's already sorted
	if (pairs.size() <= 1)
		return;

	std::list<std::pair<int, int> > left;
	std::list<std::pair<int, int> > right;
	std::list<std::pair<int, int> >::iterator middle = pairs.begin();

	std::advance(middle, pairs.size() / 2); // Move middle iterator to the midpoint of the pairs vector
	left.insert(left.end(), pairs.begin(), middle); // Copy first half to left
	right.insert(right.end(), middle, pairs.end()); // Copy second half to right

	// This is the recursive Ford-Johnson phase: sort the winners while carrying each pair's pending value
	// along with its winner.
	sortListPairs(left);
	sortListPairs(right);

	// Merge the sorted halves. Lists use iterator assignment rather than
	// random-access indexing, so each iterator is advanced explicitly.
	std::list<std::pair<int, int> >::iterator leftIt = left.begin();
	std::list<std::pair<int, int> >::iterator rightIt = right.begin();
	std::list<std::pair<int, int> >::iterator output = pairs.begin();
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

void PmergeMe::sortVectorRange(std::vector<int>& values) const {
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> mainChain;
	std::vector<int> pending;

	std::vector<int>::const_iterator end = values.end();
	bool hasStraggler = values.size() % 2 != 0;
	int straggler = 0;
	if (hasStraggler)
	{
		--end;
		straggler = *end;
	}

	// Ford-Johnson starts by comparing disjoint pairs. The larger value is
	// the pair's winner; the smaller value waits in the pending chain.
	for (std::vector<int>::const_iterator it = values.begin(); it != end; )
	{
		int first = *it;
		++it;
		int second = *it;
		++it;
		if (first < second)
			std::swap(first, second);
		pairs.push_back(std::make_pair(first, second));
	}
	
	// Sort the pairs based on the winners (first elements of the pairs)
	sortVectorPairs(pairs);

	// Build the main chain and pending chain from the sorted pairs.
	// Split the sorted pairs into the main chain (winners) and pending chain (losers)
	for (std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		mainChain.push_back(it->first);
		pending.push_back(it->second);
	}

	// Insert pending values into the main chain using reverse Jacobsthal-group order
	if (!pending.empty())
	{
		// The first pending value is smaller than the first winner, so it can be
		// inserted at the beginning without searching.
		mainChain.insert(mainChain.begin(), pending.front());

		// Ford-Johnson inserts pending values in reverse Jacobsthal-group order.
		// The boundaries 1, 3, 5, 11, 21, 43... are generated as needed;
		// the last boundary is clipped to pending.size().
		std::size_t previous = 1;
		std::size_t current = 3;
		while (previous < pending.size())
		{
			std::size_t upper = std::min(current, pending.size());
			// A vector has random-access iterators, so each group can be
			// traversed backwards by index before binary insertion.
			for (std::size_t index = upper; index > previous; --index)
			{
				std::vector<int>::iterator position = std::lower_bound(mainChain.begin(), mainChain.end(), pending[index - 1]);
				mainChain.insert(position, pending[index - 1]);
			}
			current = current + 2 * previous; // Jacobsthal sequence: J(n) = J(n-1) + 2*J(n-2)
			previous = upper;
		}
	}

	// Lastly, if there was a straggler (an unpaired element), insert it into the main chain
	if (hasStraggler)
		mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), straggler), straggler);
	values = mainChain;
}

void PmergeMe::sortListRange(std::list<int>& values) const {
	std::list<std::pair<int, int> > pairs;
	std::list<int> mainChain;
	std::list<int> pending;

	std::list<int>::const_iterator end = values.end();
	bool hasStraggler = values.size() % 2 != 0;
	int straggler = 0;
	if (hasStraggler)
	{
		--end;
		straggler = *end;
	}

	// Ford-Johnson starts by comparing disjoint pairs. The larger value is
	// the pair's winner; the smaller value waits in the pending chain.
	for (std::list<int>::const_iterator it = values.begin(); it != end; )
	{
		int first = *it;
		++it;
		int second = *it;
		++it;
		if (first < second)
			std::swap(first, second);
		pairs.push_back(std::make_pair(first, second));
	}

	// Sort the pairs based on the winners (first elements of the pairs)
	sortListPairs(pairs);

	// Build the main chain and pending chain from the sorted pairs.
	// Split the sorted pairs into the main chain (winners) and pending chain (losers)
	for (std::list<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		mainChain.push_back(it->first);
		pending.push_back(it->second);
	}

	// Insert pending values into the main chain using reverse Jacobsthal-group order
	if (!pending.empty())
	{
		// The first pending value is smaller than the first winner, so it can be
		// inserted at the beginning without searching.
		mainChain.insert(mainChain.begin(), pending.front());

		// Ford-Johnson uses the same reverse Jacobsthal groups for a list.
		// The boundaries 1, 3, 5, 11, 21, 43... are generated as needed;
		// the last boundary is clipped to pending.size().
		std::size_t previous = 1;
		std::size_t current = 3;
		while (previous < pending.size())
		{
			std::size_t upper = std::min(current, pending.size());
			// A list has no random-access iterators, so each indexed value is
			// reached by advancing from pending.begin().
			for (std::size_t index = upper; index > previous; --index)
			{
				std::list<int>::const_iterator pendingValue = pending.begin();
				std::advance(pendingValue, index - 1); // Key difference, search value twice (one for the value, one for the position)
				std::list<int>::iterator position = std::lower_bound(mainChain.begin(), mainChain.end(), *pendingValue);
				mainChain.insert(position, *pendingValue);
			}
			current = current + 2 * previous; // Jacobsthal sequence: J(n) = J(n-1) + 2*J(n-2)
			previous = upper;
		}
	}

	// Lastly, if there was a straggler (an unpaired element), insert it into the main chain
	if (hasStraggler)
		mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), straggler), straggler);
	values = mainChain;
}

// Public member functions

std::vector<int> PmergeMe::getVector() const { return _vector; }

std::list<int> PmergeMe::getList() const { return _list; }

std::vector<int> PmergeMe::sortVector() {
	sortVectorRange(_vector);
	return _vector;
}

std::list<int> PmergeMe::sortList() {
	sortListRange(_list);
	return _list;
}

bool PmergeMe::isSorted() const {
	std::vector<int>::const_iterator vectorNext = _vector.begin();
	if (vectorNext != _vector.end())
	{
		std::vector<int>::const_iterator vectorCurrent = vectorNext++;
		for (; vectorNext != _vector.end(); ++vectorCurrent, ++vectorNext)
			if (*vectorNext < *vectorCurrent)
				return false;
	}
	std::list<int>::const_iterator listNext = _list.begin();
	if (listNext != _list.end())
	{
		std::list<int>::const_iterator listCurrent = listNext++;
		for (; listNext != _list.end(); ++listCurrent, ++listNext)
			if (*listNext < *listCurrent)
				return false;
	}
	return true;
}

double timeSortingVector(PmergeMe& sorter, std::vector<int>& before, std::vector<int>& after) {
	before = sorter.getVector();
	std::clock_t start = std::clock();
	after = sorter.sortVector();
	std::clock_t end = std::clock();
	return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
}

double timeSortingList(PmergeMe& sorter, std::list<int>& before, std::list<int>& after) {
	before = sorter.getList();
	std::clock_t start = std::clock();
	after = sorter.sortList();
	std::clock_t end = std::clock();
	return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
}

