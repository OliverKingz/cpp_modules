/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:29:03 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/15 15:43:20 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain Default Constructor called\n";
	for (int i = 0; i < 100 ; i++)
		ideas[i] = "";
}

Brain::Brain(const Brain& src) {
	std::cout << "Brain Copy Constructor called\n";
	for (int i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
}

Brain::~Brain() {
	std::cout << "Brain Destructor called\n";
}

Brain& Brain::operator=(const Brain& src) {
	std::cout << "Brain Copy Assignment Operator called\n";
	if (this != &src) {
		for (int i = 0; i < 100; i++)
			ideas[i] = src.ideas[i];
	}
	return *this;
}

std::string Brain::getIdea(int index) const {return ideas[index]; }

void Brain::setIdea(int index, const std::string& idea) { ideas[index] = idea; }

void Brain::printIdea(int index) {
	if (!ideas[index].empty())
		std::cout << "Idea " << index << ": " << ideas[index] << std::endl;
	else
		std::cout << "Idea " << index << ": " << "empty" << std::endl;
}

void Brain::printAllIdeas() {
	for(int index = 0; index < 100; index++) {
		if (!ideas[index].empty()) {
			std::cout << "Idea " << index << ": " << ideas[index] << std::endl;
		}
	}
}
