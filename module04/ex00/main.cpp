/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:34:56 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/13 15:02:13 by ozamora-         ###   ########.fr       */
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

	std::cout << BOLD "\nSubject Tests: \n" RESET;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound(); // will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	std::cout << BOLD "\nSubject Wrong Tests: \n" RESET;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const Animal* j = new Dog();
		const WrongAnimal* i = new WrongCat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound(); // will output Animal sound, as it is not virtual
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	std::cout << BOLD "\nOliver Tests: \n" RESET;
	{
		const Animal* meta = new Animal();
		const Animal* doggy = new Dog();
		const Animal* kitty = new Cat();
		const WrongAnimal* wrongKitty = new WrongCat();

		std::cout << meta->getType() << " says ";
		meta->makeSound();
		std::cout << doggy->getType() << " says ";
		doggy->makeSound();
		std::cout << kitty->getType() << " says ";
		kitty->makeSound(); // will output the cat sound!
		std::cout << meta->getType() << " says ";
		wrongKitty->makeSound(); // will output Animal sound, as it is not virtual

		delete meta;
		delete doggy;
		delete kitty;
		delete wrongKitty;
	}
	std::cout <<   "================" <<         "==========================="          << "================\n\n";
	return 0;
}