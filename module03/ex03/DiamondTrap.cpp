/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:41:45 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/10 22:12:55 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap(), _name("Default")
{
	this->ClapTrap::_name = this->_name + "_clap_name";
	_hitPoints = 100;   // From FragTrap
	_energyPoints = 50; // From ScavTrap
	_attackDamage = 30; // From FragTrap
	std::cout << "DiamondTrap " BLUE << this->_name << RESET " was built" << std::endl;

	/* Due to virtual inheritance, DiamondTrap has only one set of ClapTrap protected attributes:
	- ClapTrap::_name (inherited, accessed as ClapTrap::_name)
	- _hitPoints, _energyPoints, _attackDamage (inherited, accessed directly)
	Plus DiamondTrap's own private attribute:
	- DiamondTrap::_name (separate from ClapTrap::_name)

	The following qualified assignments would be unnecessary but equivalent:
	this->FragTrap::_hitPoints = 100;     // Same as _hitPoints = 100;
	this->ScavTrap::_energyPoints = 50;   // Same as _energyPoints = 50;
	this->FragTrap::_attackDamage = 30;   // Same as _attackDamage = 30; */
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	_hitPoints = 100;   // From FragTrap
	_energyPoints = 50; // From ScavTrap
	_attackDamage = 30; // From FragTrap
	std::cout << "DiamondTrap " BLUE << this->_name << RESET " was built" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src.ClapTrap::_name), FragTrap(src._name), ScavTrap(src._name),
	_name(src._name)
{
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
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
		_name = src._name;
		ClapTrap::_name = src.ClapTrap::_name;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage; 
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
