/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:47:06 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/03 18:06:55 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "================" << BLUE << " Exercise 01: Moar brainz! " << RESET << "================\n" << std::endl;
	int n = 5;
	std::string name = "Foo";

	std::cout << BOLD << "Creating a zombie horde, all heap-allocated\n";
	Zombie* myHorde = zombieHorde(n, name);
	for (int i = 0; i < n ; i++)
	{
		myHorde[i].announce();
	}

	delete[] myHorde;
}
