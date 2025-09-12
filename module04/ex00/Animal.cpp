/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:26:46 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/12 12:06:42 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal"){
	std::cout << "Animal Default Constructor called\n";
}

Animal::Animal(const Animal& src): type(src.type){
	std::cout << "Animal Copy Constructor called\n";
}

Animal::~Animal(){
	std::cout << "Animal Destructor called\n";
}

Animal& Animal::operator=(const Animal& src){
	std::cout << "Animal Copy Assignment Operator called\n";
	if (this != &src)
	{
		this->type = src.type;
	}
	return *this;
}

std::string Animal::getType() const{
	return this->type;
}

void Animal::makeSound() const{
	std::cout << "*noises*\n";
}
