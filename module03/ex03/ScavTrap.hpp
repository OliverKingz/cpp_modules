/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:05:34 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/10 21:33:10 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

//  Inherits from ClapTrap using virtual inheritance to avoid the diamond problem
//  in multiple inheritance scenarios.
//  Virtual inheritance ensures that only one ClapTrap base subobject exists
//  when multiple derived classes inherit from ClapTrap.

class ScavTrap: virtual public ClapTrap
{
	private:

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& src);
		~ScavTrap();

		ScavTrap& operator=(const ScavTrap& src);

		// Override attack() - ScavTrap version. DiamondTrap will use this version (not ClapTrap's)
		void attack(const std::string& target); // Override (C++98: no 'override' keyword)

		void guardGate(); // Unique ScavTrap method
};

#endif