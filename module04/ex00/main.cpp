/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:34:56 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/12 12:02:28 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

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
	std::cout << BOLD "\nOliver Tests: \n" RESET;
	{
		const Animal* meta = new Animal();
		const Animal* doggy = new Dog();
		const Animal* kitty = new Cat();

		std::cout << doggy->getType() << " " << std::endl;
		std::cout << kitty->getType() << " " << std::endl;

		kitty->makeSound(); // will output the cat sound!
		doggy->makeSound();
		meta->makeSound();

		delete meta;
		delete doggy;
		delete kitty;
	}
	std::cout <<   "================" <<         "==========================="          << "================\n\n";
	return 0;
}