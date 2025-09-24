/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:26:23 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/24 18:31:14 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice") {
	std::cout << "Ice Default Constructor called\n";
}

Ice::Ice(const Ice& src) : AMateria(src._type){
	std::cout << "Ice Copy Constructor called\n";
}

Ice::~Ice() {
	std::cout << "Ice Destructor called\n";
}

Ice& Ice::operator=(const Ice& src) {
	std::cout << "Ice Copy Assignment Operator called\n";
	// if (this != &src)
	// 	this->_type = src._type; //A copy is not needed, as it will return the same
	(void)src;
	return *this;
}

AMateria* Ice::clone() const {
	AMateria* iceClone = new Ice();
	return iceClone;
}

void Ice::use(ICharacter& target) {
	std::cout << " * shoots an ice bolt at " YELLOW <<  target.getName()  << RESET " *\n";
}