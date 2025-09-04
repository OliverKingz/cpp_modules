/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:52:45 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/04 18:28:37 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << "\n===============================|" << BLUE << " Exercise 00: Aaaaand... OPEN! " << RESET << "|===============================\n";

	ClapTrap oliver("Oliver");
	ClapTrap oliverClone(oliver);
	ClapTrap def;

	oliver.attack("Brenda");
	oliver.beRepaired(5);
	oliver.takeDamage(5);

	// No energy messages
	for (size_t i = 0; i <= 8; i++) 
		oliver.beRepaired(1);
	oliver.attack("Brenda");
	oliver.beRepaired(5);
	oliver.takeDamage(5);

	// Death messages
	oliver.takeDamage(200);
	oliver.attack("Brenda");
	oliver.beRepaired(5);
	oliver.takeDamage(5);

	std::cout <<   "================================" <<         "==============================="          << "================================\n\n";
	return 0;
}