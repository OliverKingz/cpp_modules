/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:25:43 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/23 12:47:50 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp" // It needs to still include AMateria in cpp

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[4];
		size_t		_n_materias;
		AMateria**	_dropped;
		size_t		_n_drop;

	public:
		Character(void);
		Character(std::string name);
		Character(const Character& src);
		~Character(void);

		Character& operator=(const Character& src);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

};