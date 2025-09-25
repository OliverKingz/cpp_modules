/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:25:43 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/25 16:35:04 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp" // It needs to still include AMateria in cpp

class Character : public ICharacter
{
	private:
		std::string			_name;
		static const int	MAX_SLOT = 4;
		static const int	MAX_DROP = 4;
		AMateria*			_inventory[MAX_SLOT];
		AMateria*			_dropped[MAX_DROP];
		size_t				_n_materias;
		size_t				_n_drop;

		void cleanData(AMateria** data, const int max_data);
		void copyData(AMateria* const* dataSrc, AMateria** dataDest, const int max_data);

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