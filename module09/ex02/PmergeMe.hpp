/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:29:07 by ozamora-          #+#    #+#             */
/*   Updated: 2026/09/18 20:31:57 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
 #define PMERGEME_HPP

 #include "colors.hpp"

#include <utility> // For std::pair
#include <string> // For std::string
#include <vector> // For std::vector
#include <list> // For std::list

#define MAX_PRINT_SIZE 10

template <typename Container>
class PmergeMe
{
	private:
		Container _values;

		void parse(int argc, char **argv);
		void sortRange(Container& values) const;
		void createPairs(typename Container::const_iterator first, typename Container::const_iterator last, std::vector<std::pair<int, int> >& pairs) const;
		void sortPairs(std::vector<std::pair<int, int> >& pairs) const;
		void splitPairs(const std::vector<std::pair<int, int> >& pairs, Container& mainChain, Container& pending) const;
		void insertPending(Container& mainChain, const Container& pending) const;

		PmergeMe(void);

	public:
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);
		~PmergeMe();

		Container getValues() const;
		Container sort();
		bool isSorted() const;
};

template <typename Container>
void printRange(const Container& values);

template <typename Container>
double timeSort(PmergeMe<Container>& sorter, Container& before, Container& after);

#include "PmergeMe.tpp"

#endif