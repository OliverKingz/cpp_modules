/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:24:36 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/03 14:47:14 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; ++i) {
		horde[i].setName(name);
	}
	return horde;
}

// Another option: Using temporary objects
// Zombie *horde = new Zombie[N];
// for (int i = 0; i < N; ++i) {
// 	horde[i] = Zombie(name);
// }
// return horde;