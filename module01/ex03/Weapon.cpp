/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:13:46 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/03 15:33:58 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type){}

std::string Weapon::getType(void) const
{
	return _type;
}

void Weapon::setType(std::string type)
{
	_type = type;
}