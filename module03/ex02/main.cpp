/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:52:45 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/11 17:17:47 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

		oliver.attack("Brenda"); // ST overrides CT
		oliver.beRepaired(5);    // inherited from CT
		oliver.takeDamage(5);    // inherited from CT
		oliver.guardGate();      // unique from ST
	}
	{
		std::cout << "\nFragTrap Example:\n";
		FragTrap oliver("OliverFT");

		oliver.attack("Brenda"); // inhertied from CT
		oliver.beRepaired(5);    // inherited from CT
		oliver.takeDamage(5);    // inherited from CT
		oliver.highFivesGuys();  // unique from FT

		// Death messages
		oliver.takeDamage(101);
		oliver.attack("Brenda");
		oliver.beRepaired(5);
		oliver.takeDamage(5);
		oliver.highFivesGuys();
	}
	
	std::cout <<   "================================" <<         "=============================="          << "================================\n\n";
	return 0;
}