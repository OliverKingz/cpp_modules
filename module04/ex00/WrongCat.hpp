/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 14:43:29 by ozamora-          #+#    #+#             */
/*   Updated: 2025/09/13 15:04:25 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat& src);
		~WrongCat();
		WrongCat& operator=(const WrongCat& src);

		void makeSound() const; // This functions doesn't override, so it uses the base function.
};
