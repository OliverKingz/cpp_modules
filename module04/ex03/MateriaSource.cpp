/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:36:07 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/24 18:51:56 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(void) : _n_materias(0) {
	std::cout << "MateriaSource Default Constructor called\n";
	for (int i = 0 ; i < MAX_SLOT; i++)
		_memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src) : _n_materias(src._n_materias) {
	std::cout << "MateriaSource Copy Constructor called\n";
	for (int i = 0 ; i < MAX_SLOT; i++) {
		if (src._memory[i])
			_memory[i] = src._memory[i]->clone(); // Deep object copy
		else
			_memory[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource Destructor called\n";
	cleanData(_memory, MAX_SLOT);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src) {
	std::cout << "MateriaSource Copy Assignment Operator called\n";
	if (this != &src) {
		this->_n_materias = src._n_materias;
		// We empty this->memory and then fill it from src
		cleanData(this->_memory, MAX_SLOT);
		copyData(src._memory, this->_memory, MAX_SLOT);
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* src) {
	for (int i = 0 ; i < MAX_SLOT; i++) {
		if (!_memory[i]) {
			_memory[i] = src->clone();
			delete src;
			_n_materias++;
			std::cout << "The Source memorized the " BLUE << src->getType() << RESET " materia. \n";
			return ;
		}
	}
	std::cout << "The Source is already full of memory. Unable to learn. \n";
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0 ; i < MAX_SLOT; i++) {
		if (_memory[i] &&_memory[i]->getType() == type ) {
			std::cout << "The Source created the materia " BLUE << type << RESET << std::endl;
			return _memory[i]->clone();
		}
	}
	std::cout << "The Source is unable to create " BLUE << type << RESET " materia, as it isn't memorized. \n";
	return NULL;
}

void MateriaSource::cleanData(AMateria** data, const int max_data) {
	for (int i = 0; i < max_data; i++) {
		if (data[i]) {
			delete data[i];
			data[i] = NULL;
		}
	}
}

void MateriaSource::copyData(AMateria* const* dataSrc, AMateria** dataDest, const int max_data) {
	for (int i = 0 ; i < max_data; i++) {
		if (dataSrc[i])
			dataDest[i] = dataSrc[i]->clone(); // Deep object copy
		else
			dataDest[i] = NULL;
	}
}