/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:29:03 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/13 16:58:51 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain Default Constructor called\n";
}

Brain::Brain(const Brain& src) {
	std::cout << "Brain Copy Constructor called\n";
}

Brain::~Brain() {
	std::cout << "Brain Destructor called\n";
}

Brain& Brain::operator=(const Brain& src) {
	std::cout << "Brain Copy Assignment Operator called\n";
}

std::string Brain::getIdea(int index) const {return ideas[index]; }

void Brain::setIdea(int index, const std::string& idea) { ideas[index] = idea; }

void Brain::printIdea(int index) {
	std::cout << "\n Idea " << index << ": " << ideas[index] << std::endl;
}

void Brain::printAllIdeas() {
	for(int index = 0; index < 100; index++)
	{
		std::cout << "\n Idea " << index << ": " << ideas[index] << std::endl;
	}
}
