/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:47:06 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/02 14:12:05 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Exercise 01: Moar brainz!
**
** Turn-in directory: ex01/
** Files to turn in: Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp,
**                   zombieHorde.cpp
** Forbidden functions: None
**
** Description:
** Implement the function:
** - `Zombie* zombieHorde(int N, std::string name);`
**   Allocates N Zombie objects in a single allocation, initializes them with the
**   given name, and returns a pointer to the first zombie.
**
** Test the function by calling `announce()` for each zombie in the horde.
** Ensure proper memory management by using `delete` to deallocate the zombies
** and check for memory leaks.
*/
