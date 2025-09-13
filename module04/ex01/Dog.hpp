/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:44:13 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/13 16:49:11 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* _brain;

	public:
		Dog(void);
		Dog(const Dog& src);
		~Dog();
		Dog& operator=(const Dog& src);

		void makeSound() const;

		Brain* getBrain() const; // Used pointer, as it can be Null
};

#endif