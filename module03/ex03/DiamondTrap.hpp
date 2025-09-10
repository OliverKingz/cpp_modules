/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:31:30 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/10 21:32:48 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// Attribute Sources:
// - DiamondTrap::_name = user provided name
// - ClapTrap::_name = user_name + "_clap_name" (inherited base name)
// - HP: FragTrap (100)
// - EP: ScavTrap (50)
// - AD: FragTrap (30)
// - attack(): ScavTrap version
// - guardGate(): from ScavTrap
// - highFivesGuys(): from FragTrap
// - whoAmI(): unique to DiamondTrap

class DiamondTrap: public FragTrap, public ScavTrap // Multiple inheritance from both classes
{
	private:
		std::string _name; // Attribute that is different from ClapTrap::_name

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& src);
		~DiamondTrap();

		DiamondTrap& operator=(const DiamondTrap& src);

		// Override attack() - ScavTrap version. It resolves ambiguitiy
		void attack(const std::string& target); // Override (C++98: no 'override' keyword)

		void whoAmI(); // Unique DiamondTrap method
};

#endif