/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:25:43 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/23 18:18:48 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp" // It needs to still include AMateria in cpp

// IMPORTANT: The user is responsible for cleaning the dropped Materia at the end of the program
class Character : public ICharacter
{
	private:
		std::string			_name;
		static const int	MAX_DROP = 10;
		static const int	MAX_SLOT = 4;
		AMateria*			_inventory[MAX_SLOT];
		AMateria*			_dropped[MAX_DROP];
		size_t				_n_materias;
		size_t				_n_drop;

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