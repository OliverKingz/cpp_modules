/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:12:52 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/03 16:23:02 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	_weapon = NULL;
}

void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

//"<name> attacks with their <weapon type>"
//"<name> is unable to attack without a weapon"
void HumanB::attack(void) const
{
	if (_weapon)
	{
		std::cout << BLUE << _name << RESET
				<< " attacks with their " 
				<< BLUE << _weapon->getType() << RESET << std::endl;
	}
	else
	{
		std::cout << BLUE << _name << RESET
				<< " is unable to attack without a weapon\n";
	}
}