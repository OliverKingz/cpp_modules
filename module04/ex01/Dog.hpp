/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:44:13 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/15 15:35:51 by ozamora-         ###   ########.fr       */
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
		std::string getIdea(int index) const;
		void setIdea(int index, const std::string& idea); // The input string is not a copy and cannot be modified 
		void printIdea(int index);
		void printAllIdeas();
};

#endif