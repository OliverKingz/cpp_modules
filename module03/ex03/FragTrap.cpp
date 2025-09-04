/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:33:48 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/04 17:49:47 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default", 100, 100, 30)
{
	std::cout << "Default FragTrap was built\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap " << BLUE << this->_name << RESET << " was built" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src._name, src._hitPoints, src._energyPoints, src._attackDamage)
{
	std::cout << "FragTrap built as a copy of FragTrap " BLUE << src._name << RESET;
	std::cout << "\t\t\t" BLUE << this->_name << RESET "*\tHP: " << _hitPoints << " | EP: " << _energyPoints << " | AD: " << _attackDamage << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " BLUE << this->_name << RESET " was destroyed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return *this;
}

void FragTrap::highFivesGuys()
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "FragTrap " BLUE << this->_name << RESET " cannot get a high-five as it is dead\n";
		return;
	}
	else
	{
		std::cout << "FragTrap " BLUE << this->_name << RESET " wants to get a high-five.\n";
	}
}