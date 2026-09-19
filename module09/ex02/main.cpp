/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:28:38 by ozamora-          #+#    #+#             */
/*   Updated: 2026/09/18 00:56:48 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./PmergeMe [positive integers]" << std::endl;
		return 1;
	}
	try
	{
		// Vector
		PmergeMe<std::vector<int> > vectorSorter(argc, argv);
		std::vector<int> vectorBefore;
		std::vector<int> vectorAfter;

		// List
		PmergeMe<std::list<int> > listSorter(argc, argv);
		std::list<int> listBefore;
		std::list<int> listAfter;

		double vectorTime = timeSort(vectorSorter, vectorBefore, vectorAfter);
		double listTime = timeSort(listSorter, listBefore, listAfter);

		std::cout << BLUE "Before: " RESET ;
		printRange(vectorBefore);
		std::cout << BLUE "After:  " RESET;
		printRange(vectorAfter);
		std::cout << BLUE "Time to process a range of " << vectorAfter.size()
			<< " elements with std::vector: " RESET<< std::fixed
			<< std::setprecision(5) << vectorTime << " us" << std::endl;
		std::cout << BLUE "Time to process a range of " << listAfter.size()
			<< " elements with std::list:   " RESET << std::fixed
			<< std::setprecision(5) << listTime << " us" << std::endl;
		if (!vectorSorter.isSorted() || !listSorter.isSorted())
			return 1;
	}
	catch (const std::exception& error)
	{
		std::cerr << error.what() << std::endl;
		return 1;
	}
	return 0;
}