/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:52:45 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/08 16:46:03 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	std::cout << "\n===============================|" << BLUE << " Exercise 02: Repetitive work " << RESET << "|===============================\n";

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
	{
		std::cout << "\nFragTrap Example:\n";
		FragTrap oliver("OliverFT");

		oliver.attack("Brenda");
		oliver.beRepaired(5);
		oliver.takeDamage(5);
		oliver.highFivesGuys();
	}
	{
		std::cout << "\nDiamondTrap Example:\n";
		DiamondTrap oliver("OliverDT");

		oliver.attack("Brenda");
		oliver.beRepaired(5);
		oliver.takeDamage(5);
		oliver.whoAmI();
		oliver.guardGate();
		oliver.highFivesGuys();

		// No energy messages
		for (size_t i = 0; i <= 48; i++) 
			oliver.beRepaired(1);
		oliver.attack("Brenda");
		oliver.beRepaired(5);
		oliver.takeDamage(5);
		oliver.whoAmI();
		oliver.guardGate();
		oliver.highFivesGuys();

		// Death messages
		oliver.takeDamage(150);
		oliver.attack("Brenda");
		oliver.beRepaired(5);
		oliver.takeDamage(5);
		oliver.whoAmI();
		oliver.guardGate();
		oliver.highFivesGuys();
	}
	
	std::cout <<   "================================" <<         "=============================="          << "================================\n\n";
	return 0;
}