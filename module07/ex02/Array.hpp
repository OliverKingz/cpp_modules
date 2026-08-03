/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 19:18:40 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/03 19:32:03 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include "colors.hpp"

template <typename T>
class Array
{
	private:
		T*				_array;
		unsigned int	_size;
	public:
		Array(void);
		Array(unsigned int size);
		Array(const Array& src);
		Array& operator=(const Array& src);
		~Array(void);

		unsigned int	getSize(void) const;

		T&				operator[](unsigned int index); // Write
		T const&		operator[](unsigned int index) const; // Read
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array);

#include "Array.tpp" // It must be at the end, as it needs the Class definition first

#endif