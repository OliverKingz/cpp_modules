/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:47:06 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/04 18:04:54 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "================" << BLUE << " Exercise 01: Moar brainz! " << RESET << "================\n";
	int n = 5;
	std::string name = "Foo";

	std::cout << BOLD << "Creating a zombie horde, all heap-allocated\n";
	Zombie* myHorde = zombieHorde(n, name);
	for (int i = 0; i < n ; i++)
	{
		myHorde[i].announce();
	}

	delete[] myHorde;
	std::cout << "===========================================================\n";
}
