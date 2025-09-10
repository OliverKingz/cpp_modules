/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:53:21 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/10 21:23:43 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define RESET "\033[0m"
# define BOLD "\033[1m"
# define BOLD_OFF "\033[22m"
# define UNDERLINE "\033[4m"
# define UNDERLINE_OFF "\033[24m"
# define BLACK "\033[0;30m"
# define WHITE "\033[0;37m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"

#include <string>
#include <iostream>

class ClapTrap
{
	protected: // Changed from private -> protected so derived classes (ScavTrap, FragTrap) can access
		std::string	_name;        // Name inherited by all derived classes
		int			_hitPoints;   // Health points - varies by derived class
		int			_energyPoints;// Energy for actions - varies by derived class  
		int			_attackDamage;// Damage dealt - varies by derived class

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& src);
		
		// Virtual destructor MANDATORY for polymorphic base classes
		// Ensures proper cleanup: Derived destructor called first, then base
		virtual ~ClapTrap(); 

		ClapTrap& operator=(const ClapTrap& src);

		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// Virtual method - allows derived classes to override with different behavior
		virtual void attack(const std::string& target);
		
		// Protected constructor for derived classes to set custom values
		// FragTrap(100,100,30), ScavTrap(100,50,20), DiamondTrap uses combination
		ClapTrap(std::string name, int hitPoints, int energyPoints, int attackDamage);
};

#endif