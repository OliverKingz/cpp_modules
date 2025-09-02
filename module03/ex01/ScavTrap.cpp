/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:05:40 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/02 17:52:29 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){}

ScavTrap::ScavTrap(std::string& name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << BLUE << this->_name << RESET << " was built" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& src){}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " BLUE << this->_name << RESET " was destroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src){}

void ScavTrap::attack(const std::string& target){}
void ScavTrap::guardGate(){}