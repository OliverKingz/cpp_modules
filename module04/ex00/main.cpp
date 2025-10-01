/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:34:56 by ozamora-          #+#    #+#             */
/*   Updated: 2025/10/01 15:45:39 by ozamora-         ###   ########.fr       */
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
	std::cout << "\n===============|" << BLUE << " Exercise 00: Polymorphism " << RESET << "|===============\n";

	std::cout << YELLOW BOLD "\nSubject Tests: \n" RESET;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound(); // will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta; // added so there aren't leaks
		delete j;
		delete i;
	}
	std::cout << YELLOW BOLD "\nSubject Wrong Tests: \n" RESET;
	{
		const WrongAnimal* i_wAnimal = new WrongCat();
		const WrongCat* i_wCat = new WrongCat();
		const WrongAnimal* meta = new WrongAnimal();

		std::cout << i_wAnimal->getType() << " " << std::endl;
		std::cout << i_wCat->getType() << " " << std::endl;
		std::cout << meta->getType() << " " << std::endl;

		i_wAnimal->makeSound(); // will output Animal sound, as function is not virtual so it is not overriden
		i_wCat->makeSound(); // will output Cat sound, 
		meta->makeSound();

		delete meta; // added so there aren't leaks
		delete i_wAnimal;
		delete i_wCat;
	}
	std::cout << YELLOW BOLD "\nOliver Tests: \n" RESET;
	{
		const Animal* meta = new Animal();
		Dog* doggy = new Dog(); // No const, doggy object is Dog
		Cat kitty; // No memory allocation, no pointer
		const WrongAnimal* wrongKitty = new WrongCat(); 
		Animal* empty = NULL; // Empty animal
		empty = doggy; // Copy Assigment, saving Dog doggy into an Animal empty

		std::cout << std::endl;
		std::cout << meta->getType() << " says ";
		meta->makeSound();
		std::cout << doggy->getType() << " says "; //output of Dog* doggy is the same as Animal* doggy
		doggy->makeSound();
		std::cout << kitty.getType() << " says ";
		kitty.makeSound(); // will output the cat sound!
		std::cout << meta->getType() << " says ";
		wrongKitty->makeSound(); // will output Animal sound, as it is not virtual
		std::cout << empty->getType() << " says ";
		empty->makeSound(); // will output the same as doggy
		std::cout << std::endl;

		delete meta;
		std::cout << std::endl;
		delete doggy;
		std::cout << std::endl;
		delete wrongKitty;
		std::cout << std::endl;
		// As kitty is not dynamic, it will clean after the code block ends
		// empty was already cleaned when doggy was cleaned
	}
	std::cout <<   "================" <<         "==========================="          << "================\n\n";
	return 0;
}