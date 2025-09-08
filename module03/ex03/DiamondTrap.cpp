/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:41:45 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/08 16:17:51 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
	this->_name = "Default";
	this->ClapTrap::_name = this->_name + "_clap_name";
	this->FragTrap::_hitPoints = 100;
	this->ScavTrap::_energyPoints = 50;
	this->FragTrap::_attackDamage = 20;
	std::cout << "DiamondTrap " BLUE << this->_name << RESET " was built" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	this->FragTrap::_hitPoints = 100;
	this->ScavTrap::_energyPoints = 50;
	this->FragTrap::_attackDamage = 20;
	std::cout << "DiamondTrap " BLUE << this->_name << RESET " was built" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src.ClapTrap::_name), FragTrap(src.FragTrap::_name), ScavTrap(src.ScavTrap::_name),
	_name(src._name)
{
	this->FragTrap::_hitPoints = src.FragTrap::_hitPoints;
	this->ScavTrap::_energyPoints = src.ScavTrap::_energyPoints;
	this->FragTrap::_attackDamage = src.FragTrap::_attackDamage;
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
		this->ClapTrap::_name = src.ClapTrap::_name;
		this->FragTrap::_hitPoints = src.FragTrap::_hitPoints;
		this->ScavTrap::_energyPoints = src.ScavTrap::_energyPoints;
		this->FragTrap::_attackDamage = src.FragTrap::_attackDamage;
	}
	return *this;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " BLUE << this->_name << RESET " also known as ClapTrap " BLUE << this->ClapTrap::_name << RESET << std::endl;
}
