/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:44:04 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/15 16:40:13 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* _brain;

	public:
		Cat(void);
		Cat(const Cat& src);
		~Cat();
		Cat& operator=(const Cat& src);

		void makeSound() const;

		Brain* getBrain() const; // Used pointer, as it can be Null
		std::string getIdea(size_t index) const;
		void setIdea(size_t index, const std::string& idea); // The input string is not a copy and cannot be modified 
		void printIdea(size_t index);
		void printAllIdeas();
};

#endif