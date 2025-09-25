/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:26:04 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/25 17:07:19 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void) : _name("Noname"), _n_materias(0), _n_drop(0) {
	std::cout << "Character Default Constructor called for " BLUE << _name << RESET << std::endl;
	for (int i = 0 ; i < MAX_SLOT; i++)
		_inventory[i] = NULL;
	for (int i = 0 ; i < MAX_DROP; i++)
		_dropped[i] = NULL;
}

Character::Character(std::string name) : _name(name), _n_materias(0), _n_drop(0){
	std::cout << "Character Constructor called for " BLUE << _name << RESET << std::endl;
	for (int i = 0 ; i < MAX_SLOT; i++)
		_inventory[i] = NULL;
	for (int i = 0 ; i < MAX_DROP; i++)
		_dropped[i] = NULL;
}

Character::Character(const Character& src) : _name(src._name), _n_materias(src._n_materias), _n_drop(src._n_drop){
	std::cout << "Character Copy Constructor called for: " BLUE << _name << RESET << std::endl;;
	copyData(src._inventory, this->_inventory, MAX_SLOT);
	copyData(src._dropped, this->_dropped, MAX_DROP);
}

Character::~Character() {
	std::cout << "Character Destructor called for: " BLUE << _name << RESET << std::endl;
	cleanData(_inventory, MAX_SLOT);
	cleanData(_dropped, MAX_DROP);
}

Character& Character::operator=(const Character& src) {
	std::cout << "Character Copy Assignment Operator called for " BLUE << _name << RESET << " now named "  BLUE << src._name << RESET << std::endl;
	if (this != &src) {
		this->_name = src._name;
		this->_n_materias = src._n_materias;
		this->_n_drop = src._n_drop;
		cleanData(this->_inventory, MAX_SLOT); // We empty inventory and then fill it from src
		copyData(src._inventory, this->_inventory, MAX_SLOT);
		cleanData(this->_dropped, MAX_DROP); // We empty dropped and then fill it from src
		copyData(src._dropped, this->_dropped, MAX_DROP);
	}
	return *this;
}

std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << "Nothing done. Unable to equip unexisting Materia. \n";
		return;
	}
	for (int i = 0 ; i < MAX_SLOT; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			_n_materias++;
			std::cout << BLUE << _name << RESET << " equips Materia " YELLOW << m->getType() << RESET " into his inventory.\n";
			return ;
		}
	}
	std::cout << "Nothing done. Unable to equip more Materias, as " BLUE << _name << RESET "'s inventory is full.\n";
	delete m; // Destroys the Materia, as the User might not remember to do it. 
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < MAX_SLOT) {
		if (_inventory[idx]) {
			if (_n_drop < MAX_DROP) {
				std::cout << BLUE << _name << RESET " unequips Materia " YELLOW << _inventory[idx]->getType() << RESET ", dropping it on the floor.\n";
				_dropped[_n_drop] = _inventory[idx];
				_inventory[idx] = NULL;
				_n_drop++;
				_n_materias--;
			} else {
				std::cout << "Nothing done. The floor with the dropped Materia is full. Unable to unequip to avoid leaks.\n";
			}
		} else
			std::cout << "Nothing done. Unable to unequip Materia in slot " << idx << " as it doesn't exist.\n";
	} else
		std::cout << "Nothing done. Unable to unequip the selected Materia, as it is out of the valid values.\n";
}

void Character::use(int idx, ICharacter& target) {

	if (idx >= 0 && idx < MAX_SLOT) {
		if(_inventory[idx]) {
			std::cout << BLUE << _name << RESET;
			_inventory[idx]->use(target);
		} else
			std::cout << "Nothing done. Unable to use Materia in slot " << idx << " as it doesn't exist.\n";
	} else
		std::cout << "Nothing done. Unable to use the selected Materia, as it is out of the valid values. \n";
}

void Character::cleanData(AMateria** data, const int max_data) {
	for (int i = 0; i < max_data; i++) {
		if (data[i]) {
			delete data[i];
			data[i] = NULL;
		}
	}
}

void Character::copyData(AMateria* const* dataSrc, AMateria** dataDest, const int max_data) {
	for (int i = 0 ; i < max_data; i++) {
		if (dataSrc[i])
			dataDest[i] = dataSrc[i]->clone(); // Deep object copy
		else
			dataDest[i] = NULL;
	}
}