/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:24:57 by ozamora-          #+#    #+#             */
/*   Updated: 2026/09/15 20:51:43 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "RPN.hpp"

#include <iostream> // To use std::cout, std::cerr, std::endl

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED "Error" << RESET << ": invalid number of arguments." << std::endl;
		return 1;
	}
	RPN rpnCalculator;
	try {
		int result = rpnCalculator.calculateRPN(argv[1]);
		std::cout << result << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;
}