/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:53:21 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/08 16:22:34 by ozamora-         ###   ########.fr       */
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
	protected: // Changed from private so children can access
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& src);
		virtual ~ClapTrap(); 

		ClapTrap& operator=(const ClapTrap& src);

		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// Modified for Inheritance

		virtual void attack(const std::string& target); //added virtual to override

		// Added for Inheritance

		ClapTrap(std::string name, int hitPoints, int energyPoints, int attackDamage);
};

#endif