/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:53:52 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/13 16:58:47 by ozamora-         ###   ########.fr       */
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

		std::string getIdea(int index) const;
		void setIdea(int index, const std::string& idea); // The input string is not a copy and cannot be modified 
		void printIdea(int index);
		void printAllIdeas();
};

#endif