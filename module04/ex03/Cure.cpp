/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:30:19 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/22 17:19:57 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
	std::cout << "Cure Default Constructor called\n";
}

Cure::Cure(const Cure& src) : AMateria(src._type){
	std::cout << "Cure Copy Constructor called\n";
}

Cure::~Cure() {
	std::cout << "Cure Destructor called\n";
}

Cure& Cure::operator=(const Cure& src) {
	std::cout << "Cure Copy Assignment Operator called\n";
	// if (this != &src)
	// 	this->_type = src._type; //A copy is not needed, as it will return the same
	return *this;
}

AMateria* Cure::clone() const {
	AMateria* cureClone = new Cure();
	return cureClone;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}