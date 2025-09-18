/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:45:18 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/18 16:23:31 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal() {
	type = "Cat";
	_brain = new Brain();
	std::cout << "Cat Default Constructor called\n";
}

Cat::Cat(const Cat& src) : Animal(src) {
	// Attribute type is not from Cat, but from base class Animal, delegating into Animal Copy Constructor.
	_brain = new Brain(*src._brain); // dont delete before _brain, as it was not created yet
	std::cout << "Cat Copy Constructor called\n";
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat Destructor called\n";
}

Cat& Cat::operator=(const Cat& src) {
	std::cout << "Cat Copy Assignment Operator called\n";
	if (this != &src)
	{
		Animal::operator=(src);
		if (_brain)
			delete _brain;
		_brain = new Brain(*src._brain);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "\"Meow\"\n";
}

Brain* Cat::getBrain() const { return _brain;}

std::string Cat::getIdea(size_t index) const { return _brain->getIdea(index); }

void Cat::setIdea(size_t index, const std::string& idea) { _brain->setIdea(index, idea); }

void Cat::printIdea(size_t index) {
	std::cout << "Cat ";
	_brain->printIdea(index);
}

void Cat::printAllIdeas() { 
	std::cout << "Cat ";
	_brain->printAllIdeas();
}
