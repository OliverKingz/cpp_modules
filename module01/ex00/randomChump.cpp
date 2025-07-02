/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:47:20 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/02 16:42:55 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie(name).announce();
}

/*
	// Option 1: allocated on the stack (temporary instance)
	// Zombie(name).announce();

	// Option 2: allocated on the stack (named instance)
	// Zombie spawnZombie(name);
	// spawnZombie.announce();

	// Option 3: allocated on the heap using pointers
	// Zombie* dynamicZombie = new Zombie(name);
	// dynamicZombie->announce();
	// delete dynamicZombie;

	// Option 4: allocated on the heap using references
	// Zombie& referenceZombie = *(new Zombie(name));
	// referenceZombie.announce();
	// delete &referenceZombie;
*/