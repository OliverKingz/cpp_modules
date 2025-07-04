/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:12:43 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/04 17:45:14 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) 
{
	std::cout << "HumanA constructor called for " << BLUE << _name << RESET << " with a " << BLUE << _weapon.getType() << RESET << std::endl;
}

HumanA::~HumanA() 
{
	std::cout << "HumanA destructor called for " << BLUE << _name << RESET << std::endl;
}

//"<name> attacks with their <weapon type>"
void HumanA::attack(void) const
{
	std::cout << BLUE << _name << RESET
			  << " attacks with their " 
			  << BLUE << _weapon.getType() << RESET << std::endl;
}