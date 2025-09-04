/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:52:45 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/04 17:20:18 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::cout << "\n===============================|" << BLUE << " Exercise 01: Serena, my love! " << RESET << "|===============================\n";

	{
		std::cout << "ClapTrap Example:\n";
		ClapTrap oliver("OliverCT");

		oliver.attack("Brenda");
		oliver.beRepaired(5);
		oliver.takeDamage(5);
	}
	{
		std::cout << "\nScavTrap Example:\n";
		ScavTrap oliver("OliverST");

		oliver.attack("Brenda");
		oliver.beRepaired(5);
		oliver.takeDamage(5);
		oliver.guardGate();
	}
	std::cout << "\n\tWhen a ScavTrap is created, the program starts by constructing a ClapTrap. \n";
	std::cout << "\tDestruction occurs in reverse order. Why?\n";

	std::cout <<   "================================" <<         "==============================="          << "================================\n\n";
	return 0;
}