/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:33:36 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/10 21:24:24 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

//  Inherits from ClapTrap using virtual inheritance to avoid the diamond problem
//  in multiple inheritance scenarios.
//  Virtual inheritance ensures that only one ClapTrap base subobject exists
//  when multiple derived classes inherit from ClapTrap.

class FragTrap: virtual public ClapTrap 
{
	private: 

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& src);
		~FragTrap();

		FragTrap& operator=(const FragTrap& src);

		void highFivesGuys(void); // Unique FragTrap method
};

#endif