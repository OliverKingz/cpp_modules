/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:25:56 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/22 16:56:52 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type){
	std::cout << "AMateria Constructor called\n";
}

AMateria::AMateria() : _type("") {
	std::cout << "AMateria Default Constructor called\n";
}

AMateria::AMateria(const AMateria& src) : _type(src._type){
	std::cout << "AMateria Copy Constructor called\n";
}

AMateria::~AMateria() {
	std::cout << "AMateria Destructor called\n";
}

AMateria& AMateria::operator=(const AMateria& src) {
	std::cout << "AMateria Copy Assignment Operator called\n";
	if (this != &src)
		this->_type = src._type;
	return *this;
}

std::string const & AMateria::getType() const { return _type; }

void AMateria::use(ICharacter& target) { (void)target; }
