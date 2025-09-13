/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:45:18 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/12 12:03:27 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal(){
	type = "Dog";
	std::cout << "Dog Default Constructor called\n";
}

Dog::Dog(const Dog& src) : Animal(src) {
	// Attribute type is not from Dog, but from base class Animal, delegating into Animal Copy Constructor.
	std::cout << "Dog Copy Constructor called\n";
}

Dog::~Dog(){
	std::cout << "Dog Destructor called\n";
}

Dog& Dog::operator=(const Dog& src){
	std::cout << "Dog Copy Assignment Operator called\n";
	if (this != &src)
	{
		this->type = src.type;
	}
	return *this;
}

void Dog::makeSound() const{
	std::cout << "\"Woof\"\n";
}
