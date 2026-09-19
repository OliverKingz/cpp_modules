/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:28:38 by ozamora-          #+#    #+#             */
/*   Updated: 2026/09/19 11:06:24 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "PmergeMe.hpp"

#include <iomanip> // For std::setprecision(), std::fixed
#include <iostream> // For std::cout,std::cerr, std::endl

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./PmergeMe [positive integers]" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe sorter(argc, argv);

		// Vector
		std::vector<int> vectorBefore;
		std::vector<int> vectorAfter;

		// List
		std::list<int> listBefore;
		std::list<int> listAfter;

		double vectorTime = timeSortingVector(sorter, vectorBefore, vectorAfter);
		double listTime = timeSortingList(sorter, listBefore, listAfter);

		std::cout << BLUE "Before: " RESET ;
		printContainer(vectorBefore);
		std::cout << BLUE "After:  " RESET;
		printContainer(vectorAfter);
		std::cout << BLUE "Time to process a range of " << vectorAfter.size()
			<< " elements with std::vector: " RESET<< std::fixed
			<< std::setprecision(5) << vectorTime << " us" << std::endl;
		std::cout << BLUE "Time to process a range of " << listAfter.size()
			<< " elements with std::list:   " RESET << std::fixed
			<< std::setprecision(5) << listTime << " us" << std::endl;
		if (!sorter.isSorted())
			return 1;
	}
	catch (const std::exception& error)
	{
		std::cerr << error.what() << std::endl;
		return 1;
	}
	return 0;
}