/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:47:24 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/03 14:27:54 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name){}

Zombie::~Zombie()
{
	std::cout << RED << "Zombie " << GREEN << _name << RED << " is eliminated\n" << RESET;
}

void Zombie::announce(void)
{
	std::cout << GREEN << _name << RESET << ": BraiiiiiiinnnzzzZ...\n";
}
