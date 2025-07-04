/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:13:46 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/04 17:50:30 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "Weapon constructor called for weapon type " << BLUE << _type << RESET << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destructor called for weapon type " << BLUE << _type << RESET << std::endl;
}

std::string Weapon::getType(void) const
{
	return _type;
}

void Weapon::setType(std::string type)
{
	_type = type;
}