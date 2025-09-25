/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:09:14 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/25 17:10:08 by ozamora-         ###   ########.fr       */
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
	std::cout << BLUE "\nSubject Tests: \n" RESET;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << BLUE "\nOliver Tests: \n" RESET;
	{
		std::cout << GREEN "\n--- Source learning Materia ---\n" RESET;

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());  // Learned
		src->learnMateria(new Cure()); // Learned
		src->learnMateria(new Cure()); // Learned
		src->learnMateria(new Cure()); // Learned
		src->learnMateria(new Cure()); // Destroyed

		std::cout << GREEN "\n--- Source creating Materia ---\n" RESET;

		AMateria* tmp0 = src->createMateria("cure");
		AMateria* tmp1 = src->createMateria("ice");
		AMateria* tmp2 = src->createMateria("cure");
		AMateria* tmp3 = src->createMateria("ice");
		AMateria* tmp4 = src->createMateria("cure");

		std::cout << GREEN "\n--- Character Creation ---\n" RESET;

		Character* oliver = new Character("Oliver"); // Named constructor
		Character* brenda = new Character("Brenda");

		std::cout << GREEN "\n--- Character equiping Materia ---\n" RESET;

		oliver->equip(tmp0); // Equiped
		oliver->equip(tmp1); // Equiped
		oliver->equip(tmp2); // Equiped
		oliver->equip(tmp3); // Equiped
		oliver->equip(tmp4); // Inventory full. Materia Destroyed

		std::cout << GREEN "\n--- Character using equiped Materia ---\n" RESET;
		oliver->use(0, *brenda); // Used cure
		oliver->use(1, *brenda); // Used ice
		oliver->use(2, *brenda); // Used cure
		oliver->use(3, *brenda); // Used ice
		oliver->use(4, *brenda); // Unable to use, unexisting slot

		std::cout << GREEN "\n--- Character unequiping and dropping Materia ---\n" RESET;
		oliver->unequip(0); // Dropped
		oliver->unequip(1); // Dropped
		oliver->unequip(2); // Dropped
		oliver->unequip(3); // Dropped
		oliver->unequip(3); // Empty slot
		oliver->unequip(4); // Unable to unequip, unexisting slot

		std::cout << GREEN "\n--- Dropped materia full ---\n" RESET;
		oliver->equip(src->createMateria("cure")); 
		oliver->unequip(0); // Not dropped, still equiped. The floor with dropped Materia is full. 

		std::cout << GREEN "\n--- Other Character Constructors (Deep Copy) ---\n" RESET;
		Character oliverClone(*oliver); // Copy construtor
		Character noname;				// Default constructor
		noname = *oliver;				// Assigment constructor

		std::cout << GREEN "\n--- Manual Destructor ---\n" RESET;
		delete src;
		delete brenda;
		delete oliver;

		std::cout << GREEN "\n--- Automatic Destructor ---\n" RESET;
	}
	std::cout <<   "================" <<         "================================"          << "================\n\n";
	return 0;
}