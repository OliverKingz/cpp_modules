/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:09:14 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/24 18:34:08 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	std::cout << "\n===============|" << BLUE << " Exercise 03: Interface & recap " << RESET << "|===============\n";
	{
		// IMateriaSource* src = new MateriaSource();
		// src->learnMateria(new Ice());
		// src->learnMateria(new Cure());

		// ICharacter* me = new Character("me");

		// AMateria* tmp;
		// tmp = src->createMateria("ice");
		// me->equip(tmp);
		// tmp = src->createMateria("cure");
		// me->equip(tmp);

		// ICharacter* bob = new Character("bob");
		// me->use(0, *bob);
		// me->use(1, *bob);

		// delete bob;
		// delete me;
		// delete src;
		// delete character->_dropped[i];
	}

	{
		std::cout << "\n--- Default constructor ---\n";
		Character c1;
		std::cout << "\n--- Named constructor ---\n";
		Character c2("Oliver");

		std::cout << "\n--- Equip Materias ---\n";
		c2.equip(new Ice());
		c2.equip(new Cure());
		c2.equip(new Ice());
		c2.equip(new Cure());
		c2.equip(new Ice()); // Should not equip (inventory full)

		std::cout << "\n--- Use Materias ---\n";
		c2.use(0, c2); // Use Ice
		c2.use(1, c2); // Use Cure
		c2.use(4, c2); // Invalid index
		c2.use(2, c1); // Use Ice on another character

		std::cout << "\n--- Unequip Materias ---\n";
		c2.unequip(1); // Unequip Cure
		c2.unequip(3); // Unequip Cure
		c2.unequip(4); // Invalid index
		c2.unequip(1); // Already empty

		std::cout << "\n--- Equip after unequip ---\n";
		c2.equip(new Cure());
		c2.equip(new Ice());

		std::cout << "\n--- Copy constructor ---\n";
		Character c3(c2);

		std::cout << "\n--- Assignment operator ---\n";
		Character c4("Brenda");
		c4 = c2;

		std::cout << "\n--- Use on copies ---\n";
		c3.use(0, c4);
		c4.use(1, c3);

		std::cout << "\n--- Automatic Destructor test ---\n";
		// All destructors will be called automatically for c1, c2, c3, c4
		// Dropped Materias must be deleted manually to avoid leaks
	}
	std::cout <<   "================" <<         "================================"          << "================\n\n";
	return 0;
}