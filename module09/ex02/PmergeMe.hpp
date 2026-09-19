/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:29:07 by ozamora-          #+#    #+#             */
/*   Updated: 2026/09/19 13:15:48 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
 #define PMERGEME_HPP

 #include "colors.hpp"

#include <utility> // For std::pair
#include <string> // For std::string
#include <vector> // For std::vector
#include <list> // For std::list
#include <iostream> // For std::cout, std::endl

#define MAX_PRINT_SIZE 10

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::list<int> _list;

		void parse(int argc, char **argv);
		void sortVectorRange(std::vector<int>& values) const;
		void sortListRange(std::list<int>& values) const;
		void sortVectorPairs(std::vector<std::pair<int, int> >& pairs) const;
		void sortListPairs(std::list<std::pair<int, int> >& pairs) const;

		PmergeMe(void);

	public:
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);
		~PmergeMe();

		std::vector<int>	getVector() const;
		std::list<int>		getList() const;
	
		std::vector<int>	sortVector();
		std::list<int>		sortList();

		bool isSorted() const;
};

double timeSortingVector(PmergeMe& sorter, std::vector<int>& before, std::vector<int>& after);
double timeSortingList(PmergeMe& sorter, std::list<int>& before, std::list<int>& after);

template <typename Container>
void printContainer(const Container& values)
{
	int count = 0;
	for (typename Container::const_iterator it = values.begin();
		it != values.end() && count < MAX_PRINT_SIZE; ++it, ++count)
		std::cout << *it << ' ';
	if (values.size() > MAX_PRINT_SIZE)
		std::cout << "[...]";
	std::cout << std::endl;
}

#endif