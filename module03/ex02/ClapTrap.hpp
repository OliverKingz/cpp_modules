/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:53:21 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/11 17:06:30 by ozamora-         ###   ########.fr       */
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
	protected: // Changed from private -> protected so derived classes  can access
		std::string	_name;        // Name inherited by all derived classes
		int			_hitPoints;   // Health points - varies by derived class
		int			_energyPoints;// Energy for actions - varies by derived class  
		int			_attackDamage;// Damage dealt - varies by derived class

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& src);
		~ClapTrap();

		ClapTrap& operator=(const ClapTrap& src);

		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// Virtual method - allows derived classes to override with different behavior
		virtual void attack(const std::string& target); // added virtual to override

		// Protected constructor for derived classes to set custom values
		ClapTrap(std::string name, int hitPoints, int energyPoints, int attackDamage); // added for easier use
};

#endif