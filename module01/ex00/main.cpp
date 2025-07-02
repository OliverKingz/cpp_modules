/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:47:06 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/02 16:55:34 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"

int main()
{
	std::cout << BLUE << "\nCreating a pointer heap-allocated zombie: needs to personally delete\n" << RESET;
	Zombie* pointerDynamicZombie = new Zombie("pointerDynamicZombie");
	pointerDynamicZombie->announce();
	delete pointerDynamicZombie; // it triggers destructor ~Zombie()

	std::cout << BLUE << "\nCreating a reference heap-allocated zombie: needs to personally delete\n" << RESET;
	Zombie& refDynamicZombie = *(new Zombie("refDynamicZombie"));
	refDynamicZombie.announce();
	delete &refDynamicZombie; // it triggers destructor ~Zombie()

	std::cout << BLUE << "\nCreating a temporary stack-allocated zombie: automatically deletes immediately\n" << RESET;
	randomChump("tempStackZombie");

	std::cout << BLUE << "\nCreating a stack-allocated zombie: automatically deletes at the end\n" << RESET;
	Zombie stackZombie("stackZombie");
	stackZombie.announce();

	std::cout << BLUE << "\nCreating a named stack-allocated zombie: automatically deletes at the end\n" << RESET;
	Zombie namedStackZombie = Zombie("namedStackZombie");
	namedStackZombie.announce();

	return 0;
}

/*
** Exercise 00: Zombie Exercise
**
** Turn-in directory: ex00/
** Files to turn in: Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp,
**                   newZombie.cpp, randomChump.cpp
** Forbidden functions: None
**
** Description:
** Implement a Zombie class with the following features:
** - A private string attribute `name`.
** - A member function `void announce(void)` that makes the zombie announce
**   itself in the format: "<name>: BraiiiiiiinnnzzzZ...".
**
** Additionally, implement two functions:
** - `Zombie* newZombie(std::string name);`
**   Creates a zombie, names it, and returns it for use outside the function scope.
**
** - `void randomChump(std::string name);`
**   Creates a zombie, names it, and makes it announce itself immediately.
**
** The exercise focuses on determining when to allocate zombies on the stack
** versus the heap. Zombies must be destroyed when no longer needed, and the
** destructor should print a message with the zombie's name for debugging purposes.
*/