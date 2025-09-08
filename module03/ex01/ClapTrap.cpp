/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:53:34 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/08 16:44:34 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default ClapTrap was built\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " BLUE << this->_name << RESET " was built" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) : _name(src._name), _hitPoints(src._hitPoints), 
	_energyPoints(src._energyPoints), _attackDamage(src._attackDamage)
{
	std::cout << "ClapTrap built as a copy of ClapTrap " BLUE << src._name << RESET;
	std::cout << "\t\t\t" BLUE << this->_name << RESET "*\tHP: " << _hitPoints << " | EP: " << _energyPoints << " | AD: " << _attackDamage << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " BLUE << this->_name << RESET " was destroyed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
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

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " BLUE << this->_name << RESET " cannot attack " << target << " as it is already dead!" << std::endl;
		return;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " BLUE << this->_name << RESET " cannot attack " << target << " as it has no EP left!" << std::endl;
		return;
	}
	else
	{
		this->_energyPoints -= 1;
		// ClapTrap enemy(target);
		std::cout << "ClapTrap " BLUE << this->_name << RESET " attacks " BLUE << target << RESET ", causing " << this->_attackDamage << " points of damage!\n";
		// enemy.takeDamage(this->_attackDamage);
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " BLUE << this->_name << RESET " cannot take more damage, as is already dead!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " BLUE << this->_name << RESET" takes " << amount << " points of damage!";
	this->_hitPoints -= amount;
	std::cout << "\t\t\t" BLUE << this->_name << RESET "\tHP: " RED << _hitPoints << RESET " | EP: " << _energyPoints << " | AD: " << _attackDamage << std::endl;
	if (this->_hitPoints <= 0)
	{
		std::cout << RED "ClapTrap " BLUE << this->_name << RED " was killed!" RESET << std::endl;
		return;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " BLUE << this->_name << RESET " cannot repair itself as it is dead!" << std::endl;
		return;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " BLUE << this->_name << RESET " cannot repair itself as it has no EP left!" << std::endl;
		return;
	}
	this->_energyPoints -= 1;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " BLUE << this->_name << RESET " repairs itself " << amount << " hit points (HP)!";
	std::cout << "\t\t" BLUE << this->_name << RESET "\tHP: " GREEN << _hitPoints << RESET " | EP: " << _energyPoints << " | AD: " << _attackDamage << std::endl;
}

// Added to use inheritance

ClapTrap::ClapTrap(std::string name, int hitPoints, int energyPoints, int attackDamage) : 
	_name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage)
{
	std::cout << "ClapTrap " BLUE << this->_name << RESET " was built" << std::endl;
}