/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:12:43 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/03 15:43:02 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}

//"<name> attacks with their <weapon type>"
void HumanA::attack(void) const
{
	std::cout << BLUE << _name << RESET
			  << " attacks with their " 
			  << BLUE << _weapon.getType() << RESET << std::endl;
}