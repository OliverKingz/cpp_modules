/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:43:24 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/13 15:43:41 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal(){
	type = "WrongCat";
	std::cout << "WrongCat Default Constructor called\n";
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src) {
	// Attribute type is not from WrongCat, but from base class WrongCat, delegating into WrongCat Copy Constructor.
	std::cout << "WrongCat Copy Constructor called\n";
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat Destructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& src){
	std::cout << "WrongCat Copy Assignment Operator called\n";
	if (this != &src)
	{
		WrongAnimal::operator=(src);
	}
	return *this;
}

void WrongCat::makeSound() const{
	std::cout << "\"Meow\"\n";
}
