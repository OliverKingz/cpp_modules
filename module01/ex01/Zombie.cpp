/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:47:24 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/03 14:31:28 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor

Zombie::Zombie(){}

Zombie::Zombie(std::string name) : _name(name){}

// Destructor

Zombie::~Zombie()
{
	std::cout << RED << "Zombie " << GREEN << _name << RED << " is eliminated\n" << RESET;
}

// Getters

std::string Zombie::getName() const
{
	return _name;
}

// Setters

void Zombie::setName(std::string name)
{
	_name = name;
}

// Functions

void Zombie::announce(void)
{
	std::cout << GREEN << _name << RESET << ": BraiiiiiiinnnzzzZ...\n";
}
