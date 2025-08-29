/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:53:34 by ozamora-          #+#    #+#             */
/*   Updated: 2025/08/29 21:37:38 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default ClapTrap was built\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " was built" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& src) : _name(src._name), _hitPoints(src._hitPoints), _energyPoints(src._energyPoints), _attackDamage(src._attackDamage)
{
	std::cout << "ClapTrap built as a copy of \"" << src._name;
	std::cout << "\" with HP: " << _hitPoints << " | EP: " << _energyPoints << " | AD: " << _attackDamage << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " was destroyed" << std::endl;
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

// void ClapTrap::attack(const std::string& target){}
// void ClapTrap::takeDamage(unsigned int amount){}
// void ClapTrap::beRepaired(unsigned int amount){}
