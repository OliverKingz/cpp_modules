/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:26:04 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/23 18:18:04 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void) : _name(""), _n_materias(0), _n_drop(0) {
	std::cout << "Character Default Constructor called for: " BLUE << _name << RESET << std::endl;
	for (int i = 0 ; i < MAX_SLOT; i++)
		_inventory[i] = NULL;
	for (int i = 0 ; i < MAX_DROP; i++)
		_dropped[i] = NULL;
}

Character::Character(std::string name) : _name(name), _n_materias(0), _n_drop(0){
	std::cout << "Character Constructor called for: " BLUE << _name << RESET << std::endl;;
	for (int i = 0 ; i < MAX_SLOT; i++)
		_inventory[i] = NULL;
	for (int i = 0 ; i < MAX_DROP; i++)
		_dropped[i] = NULL;
}

Character::Character(const Character& src) : _name(src._name), _n_materias(src._n_materias), _n_drop(src._n_drop){
	std::cout << "Character Copy Constructor called for: " BLUE << _name << RESET << std::endl;;
	for (int i = 0 ; i < MAX_SLOT; i++) {
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone(); // Deep object copy
		else
			_inventory[i] = NULL;
	}
	for (int i = 0 ; i < MAX_DROP; i++) {
		if (src._dropped[i])
			_dropped[i] = src._dropped[i]; // Just copying the pointer
		else
			_dropped[i] = NULL;
	}
}

Character::~Character() {
	std::cout << "Character Destructor called for: " BLUE << _name << RESET << std::endl;
	for (int i = 0; i < MAX_SLOT; i++) {
		if (_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	// IMPORTANT: The user is responsible for cleaning the dropped Materia at the end of the program
	
	// for (int i = 0; i < MAX_DROP; i++) {
	// 	if (_dropped[i]) {
	// 		delete _dropped[i];
	// 		_dropped[i] = NULL;
	// 	}
	// }
}

Character& Character::operator=(const Character& src) {
	std::cout << "Character Copy Assignment Operator called for: " BLUE << _name << RESET << std::endl;;
	if (this != &src) {
		this->_name = src._name;
		this->_n_materias = src._n_materias;
		this->_n_drop = src._n_drop;
		// We empty this->inventory and then fill it from src
		for (int i = 0; i < MAX_SLOT; i++) {
			if (this->_inventory[i]) {
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
		}
		for (int i = 0 ; i < MAX_SLOT; i++) {
			if (src._inventory[i])
				this->_inventory[i] = src._inventory[i]->clone(); // Deep object copy
			else
				this->_inventory[i] = NULL;
		}
		// We empty this->_dropped and then fill it from src
		for (int i = 0 ; i < MAX_DROP; i++) {
			if (src._dropped[i])
				this->_dropped[i] = src._dropped[i]; // Just copying the pointer
			else
				this->_dropped[i] = NULL;
		}
	}
	return *this;
}

std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << "Unable to equip Materia. \n";
		return;
	}
	for (int i = 0 ; i < MAX_SLOT; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			_n_materias++;
			std::cout << BLUE << _name << RESET << " equips Materia " << m->getType() << " into his inventory.\n";
			return ;
		}
	}
	std::cout << "Unable to equip more Materias, as " BLUE << _name << RESET "'s inventory is full. Dropped\n";
	
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < MAX_SLOT) {
		if (_inventory[idx]) {
			if (_n_drop < MAX_DROP) {
				std::cout << BLUE << _name << RESET " unequips Materia " << _inventory[idx]->getType() << ", dropping it on the floor.\n";
				_dropped[_n_drop] = _inventory[idx];
				_inventory[idx] = NULL;
				_n_drop++;
				_n_materias--;
			} else
				std::cout << "Drop storage full, cannot save unequipped Materia.\n";
		} else
			std::cout << "Unable to unequip Materia in slot " << idx << " as it doesn't exist.\n";
	} else
		std::cout << "Unable to unequip the selected Materia, as it is out of the valid values";
}

void Character::use(int idx, ICharacter& target) {

	if (idx >= 0 && idx < MAX_SLOT) {
		if(_inventory[idx]) {
			std::cout << BLUE << _name << RESET;
			_inventory[idx]->use(target);
		} else
			std::cout << "Unable to use Materia in slot " << idx << " as it doesn't exist.\n";
	} else
		std::cout << "Unable to use the selected Materia, as it is out of the valid values";
}
