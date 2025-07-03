/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:47:06 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/03 18:05:54 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "===================" << BLUE << " Exercise 00: BraiiiiiiinnnzzzZ " << RESET << "===================\n" << std::endl;

	std::cout << BOLD << "Creating a pointer heap-allocated zombie: needs to personally delete\n" << RESET;
	Zombie* pointerDynamicZombie = new Zombie("pointerDynamicZombie");
	pointerDynamicZombie->announce();
	delete pointerDynamicZombie; // it triggers destructor ~Zombie()

	std::cout << BOLD << "\nCreating a reference heap-allocated zombie: needs to personally delete\n" << RESET;
	Zombie& refDynamicZombie = *(new Zombie("refDynamicZombie"));
	refDynamicZombie.announce();
	delete &refDynamicZombie; // it triggers destructor ~Zombie()

	std::cout << BOLD << "\nCreating a temporary stack-allocated zombie: automatically deletes immediately\n" << RESET;
	randomChump("tempStackZombie");

	std::cout << BOLD << "\nCreating a stack-allocated zombie: automatically deletes at the end\n" << RESET;
	Zombie stackZombie("stackZombie");
	stackZombie.announce();

	std::cout << BOLD << "\nCreating a named stack-allocated zombie: automatically deletes at the end\n" << RESET;
	Zombie namedStackZombie = Zombie("namedStackZombie");
	namedStackZombie.announce();

	return 0;
}

