/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:34:56 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/13 15:53:17 by ozamora-         ###   ########.fr       */
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
		const Animal* i = new Cat();

		delete j; //should not create a leak
		delete i;
	}
	std::cout << YELLOW BOLD "\nOliver Tests: \n" RESET;
	{

	}
	std::cout <<   "================" <<         "===================================================="          << "================\n\n";
	return 0;
}