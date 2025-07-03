/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:13:51 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/03 16:17:08 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

# define RESET "\033[0m"
# define UNDERLINE "\033[4m"
# define BLUE "\033[0;34m"

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string type);
		std::string getType(void) const;
		void setType(std::string type);
};

#endif