/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 19:18:31 by ozamora-          #+#    #+#             */
/*   Updated: 2026/07/29 19:18:33 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Class.hpp"

int main()
{
	std::cout << "\n===============|" << BLUE << " Exercise X: template of main " << RESET << "|===============\n";
	Class *example = new Class();
	delete example;	
	std::cout <<   "================" <<         "=============================="          << "================\n\n";
	return 0;
}