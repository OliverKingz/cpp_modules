/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:43:21 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/13 14:53:55 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal"){
	std::cout << "WrongAnimal Default Constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& src): type(src.type){
	std::cout << "WrongAnimal Copy Constructor called\n";
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal Destructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src){
	std::cout << "WrongAnimal Copy Assignment Operator called\n";
	if (this != &src)
	{
		this->type = src.type;
	}
	return *this;
}

std::string WrongAnimal::getType() const{
	return this->type;
}

void WrongAnimal::makeSound() const{
	std::cout << "*noises*\n";
}
