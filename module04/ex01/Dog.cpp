/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:45:18 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/15 15:46:36 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal(){
	type = "Dog";
	_brain = new Brain();
	std::cout << "Dog Default Constructor called\n";
}

Dog::Dog(const Dog& src) : Animal(src) {
	// Attribute type is not from Dog, but from base class Animal, delegating into Animal Copy Constructor.
	_brain = new Brain(*src._brain); // dont delete before _brain, as it was not created yet
	std::cout << "Dog Copy Constructor called\n";
}

Dog::~Dog(){
	delete _brain;
	std::cout << "Dog Destructor called\n";
}

Dog& Dog::operator=(const Dog& src){
	std::cout << "Dog Copy Assignment Operator called\n";
	if (this != &src)
	{
		Animal::operator=(src);
		delete _brain;
		_brain = new Brain(*src._brain);
	}
	return *this;
}

void Dog::makeSound() const{
	std::cout << "\"Woof\"\n";
}

Brain* Dog::getBrain() const { return _brain;}

std::string Dog::getIdea(int index) const { return _brain->getIdea(index); }

void Dog::setIdea(int index, const std::string& idea) { _brain->setIdea(index, idea); }

void Dog::printIdea(int index) {
	std::cout << "Dog ";
	 _brain->printIdea(index);
}

void Dog::printAllIdeas() {
	std::cout << "Dog ";
	_brain->printAllIdeas();
}
