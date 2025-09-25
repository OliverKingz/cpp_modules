/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:34:55 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/25 15:25:34 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "colors.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		static const int	MAX_SLOT = 4;
		AMateria*			_memory[MAX_SLOT];
		size_t				_n_materias;

		void cleanData(AMateria** data, const int max_data);
		void copyData(AMateria* const* dataSrc, AMateria** dataDest, const int max_data);

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& src);
		~MateriaSource();

		MateriaSource& operator=(const MateriaSource& src);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};