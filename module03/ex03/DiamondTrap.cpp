/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:41:45 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/04 18:52:03 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default DiamondTrap was built\n";
}

DiamondTrap::DiamondTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "DiamondTrap " BLUE << this->_name << RESET " was built" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : _name(src._name), _hitPoints(src._hitPoints), 
	_energyPoints(src._energyPoints), _attackDamage(src._attackDamage)
{
	std::cout << "DiamondTrap built as a copy of DiamondTrap " BLUE << src._name << RESET;
	std::cout << "\t\t\t" BLUE << this->_name << RESET "*\tHP: " << _hitPoints << " | EP: " << _energyPoints << " | AD: " << _attackDamage << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " BLUE << this->_name << RESET " was destroyed" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
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

void DiamondTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "DiamondTrap " BLUE << this->_name << RESET " cannot attack " << target << " as it is already dead!" << std::endl;
		return;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "DiamondTrap " BLUE << this->_name << RESET " cannot attack " << target << " as it has no energy points(EP) left!" << std::endl;
		return;
	}
	else
	{
		this->_energyPoints -= 1;
		std::cout << "DiamondTrap " BLUE << this->_name << RESET " attacks " BLUE << target << RESET ", causing " << this->_attackDamage << " points of damage!\n";
	}
}

void DiamondTrap::whoAmI()
{

}
