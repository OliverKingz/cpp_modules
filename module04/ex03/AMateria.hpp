/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:17:11 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/22 16:45:00 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "colors.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria(std::string const & type);

		AMateria();
		AMateria(const AMateria& src);
		~AMateria();
		AMateria& operator=(const AMateria& src);

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};