/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:45:18 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/12 12:02:51 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal(){
	type = "Cat";
	std::cout << "Cat Default Constructor called\n";
}

Cat::Cat(const Cat& src) : Animal(src) {
	// Attribute type is not from Cat, but from base class Animal, delegating into Animal Copy Constructor.
	std::cout << "Cat Copy Constructor called\n";
}

Cat::~Cat(){
	std::cout << "Cat Destructor called\n";
}

Cat& Cat::operator=(const Cat& src){
	std::cout << "Cat Copy Assignment Operator called\n";
	if (this != &src)
	{
		this->type = src.type;
	}
	return *this;
}

void Cat::makeSound() const{
	std::cout << "\"Meow\"\n";
}
