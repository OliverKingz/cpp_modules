/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:34:56 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/18 15:26:35 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n===============|" << BLUE << " Exercise 01: I don’t want to set the world on fire " << RESET << "|===============\n";

	std::cout << YELLOW BOLD "\nSubject Tests: \n" RESET;
	{
		const Animal* j = new Dog();
		std::cout << std::endl;
		const Animal* i = new Cat();
		std::cout << std::endl;

		delete j; //should not create a leak
		std::cout << std::endl;
		delete i;
		std::cout << std::endl;
	}

	std::cout << YELLOW BOLD "\nOliver Tests: \n" RESET;
	{
		Animal* oliver = new Animal();
		std::cout << std::endl;

		Dog* doggy = new Dog();
		std::cout << std::endl;

		Cat* catty = new Cat();
		std::cout << std::endl;

		Cat cattyCopy(*catty); // Copy Constructor
		std::cout << std::endl;

		Cat* cattyCopyOperator = new Cat();
		*cattyCopyOperator = cattyCopy; // Copy Assignment Operator
		std::cout << std::endl;

		std::string idea0 = "I am hungry...";
		doggy->setIdea(0, idea0);
		doggy->printIdea(1);
		doggy->printAllIdeas();
		std::cout << std::endl;

		std::cout << "Size of animal_ptr:    " << sizeof(oliver) << std::endl;  // Pointer size is 8
		std::cout << "Size of dog_ptr:       " << sizeof(doggy) << std::endl;   // Pointer size is 8
		std::cout << "Size of animal object: " << sizeof(*oliver) << std::endl; // Animal object size: string(32) + vtable(8)
		std::cout << "Size of dog object:    " << sizeof(*doggy) << std::endl;  // Animal(40) + brain_ptr(8)
		std::cout << "Size of cat object:    " << sizeof(*catty) << std::endl;  // Animal(40) + brain_ptr(8)
		std::cout << "Size of brain object:  " << sizeof(*doggy->getBrain()) << std::endl; // Brain object(32 string * 100)

		delete oliver;
		std::cout << std::endl;
		delete doggy;
		std::cout << std::endl;
		delete catty;
		std::cout << std::endl;
		delete cattyCopyOperator;
		std::cout << std::endl;
		// cattyCopy is a stack object and will be destroyed automatically
	}
	std::cout <<   "================" <<         "===================================================="          << "================\n\n";
	return 0;
}