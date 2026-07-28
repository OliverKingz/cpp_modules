/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:22:59 by ozamora-          #+#    #+#             */
/*   Updated: 2026/07/28 15:34:48 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Data.hpp"
#include <string>
#include <iostream>
#include <stdint.h> // To use uintptr_t
#include "colors.hpp"

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer& src);
		Serializer& operator=(const Serializer& src);
		~Serializer(void);

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};