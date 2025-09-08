/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:05:40 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/08 16:44:33 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default", 100, 50, 20)
{
	std::cout << "Default ScavTrap was built\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap " << BLUE << this->_name << RESET << " was built" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src._name, src._hitPoints, src._energyPoints, src._attackDamage)
{
	std::cout << "ScavTrap built as a copy of ScavTrap " BLUE << src._name << RESET;
	std::cout << "\t\t\t" BLUE << this->_name << RESET "*\tHP: " << _hitPoints << " | EP: " << _energyPoints << " | AD: " << _attackDamage << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " BLUE << this->_name << RESET " was destroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
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

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " BLUE << this->_name << RESET " cannot attack " << target << " as it is already dead!" << std::endl;
		return;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " BLUE << this->_name << RESET " cannot attack " << target << " as it has no EP left!" << std::endl;
		return;
	}
	else
	{
		this->_energyPoints -= 1;
		// ClapTrap enemy(target);
		std::cout << "ScavTrap " BLUE << this->_name << RESET " attacks " BLUE << target << RESET ", causing " << this->_attackDamage << " points of damage!\n";
		// enemy.takeDamage(this->_attackDamage);
	}
}

void ScavTrap::guardGate()
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " BLUE << this->_name << RESET " cannot change into Gate Keeper mode as it is dead\n";
		return;
	}
	else
	{
		std::cout << "ScavTrap " BLUE << this->_name << RESET " is now in " << YELLOW "Gate keeper mode\n" RESET;
	}
}