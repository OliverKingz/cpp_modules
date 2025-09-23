/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:26:04 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/23 13:02:05 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void) : _name(""), _n_materias(0), _dropped(NULL), _n_drop(0) {
	std::cout << "Character Default Constructor called for: " BLUE << _name << RESET << std::endl;
	for (int i = 0 ; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(void) : _name(""), _n_materias(0), _n_drop(0) {
	std::cout << "Character Default Constructor called for: " BLUE << _name << RESET << std::endl;;
}

Character::Character(std::string name) : _name(name), _n_materias(0), _dropped(NULL), _n_drop(0){
	std::cout << "Character Constructor called for: " BLUE << _name << RESET << std::endl;;
	for (int i = 0 ; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& src) : _name(src._name), _n_materias(src._n_materias), _dropped(src._dropped), _n_drop(src._n_drop){
	std::cout << "Character Copy Constructor called for: " BLUE << _name << RESET << std::endl;;
	for (int i = 0 ; i < 4; i++)
	{
		if (i < src._n_materias)
			_inventory[i] = src._inventory[i]->clone(); // Deep object copy
		else
			_inventory[i] = NULL;
	}
}

Character::~Character() {
	std::cout << "Character Destructor called for: " BLUE << _name << RESET << std::endl;;
	for (int i = 0 ; i < 4; i++)
	{
		if (i < _n_materias)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		else
			_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& src) {
	std::cout << "Character Copy Assignment Operator called for: " BLUE << _name << RESET << std::endl;;
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0 ; i < 4; i++)
		{
			if (i < src._n_materias)
				this->_inventory[i] = src._inventory[i]->clone(); // Deep object copy
			else
				this->_inventory[i] = NULL;
		}
		this->_n_materias = src._n_materias;
		this->_dropped = src._dropped;
		this->_n_drop = src._n_drop;
	}
	return *this;
}

std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	
}

void Character::unequip(int idx) {
	
}

void Character::use(int idx, ICharacter& target) {
	
}
