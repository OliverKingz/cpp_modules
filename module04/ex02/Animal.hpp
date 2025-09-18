/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:36:19 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/18 15:41:15 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "colors.hpp"

class Animal
{
	private:

	protected:
		std::string	type;

	public:
		Animal(void);
		Animal(const Animal& src);
		virtual ~Animal();
		Animal& operator=(const Animal& src);

		std::string getType() const;

		virtual void makeSound() const = 0; // Abstract (pure virtual class)
		// If a class has one or more pure virtual functions,
		// it becomes an abstract class and cannot be instantiated.
		// Derived classes must implement all pure virtual functions to become concrete
};

#endif