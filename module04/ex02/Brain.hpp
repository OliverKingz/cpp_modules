/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:53:52 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/15 16:40:13 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "colors.hpp"

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain(void);
		Brain(const Brain& src);
		~Brain();
		Brain& operator=(const Brain& src);

		std::string getIdea(size_t index) const;
		void setIdea(size_t index, const std::string& idea); // The input string is not a copy and cannot be modified 
		void printIdea(size_t index);
		void printAllIdeas();
};

#endif