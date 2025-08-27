/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:01:04 by ozamora-          #+#    #+#             */
/*   Updated: 2025/08/27 21:28:52 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath> // To use allowed function roundf

# define RESET "\033[0m"
# define BOLD "\033[1m"
# define BOLD_OFF "\033[22m"
# define UNDERLINE "\033[4m"
# define UNDERLINE_OFF "\033[24m"
# define BLACK "\033[0;30m"
# define WHITE "\033[0;37m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"

class Fixed
{
	private:
		static const int	_fractionalBits;
		int					_rawBits;
	public:

		// Constructor

		Fixed();
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed(const Fixed& other);

		// Destructor

		~Fixed();

		// Other operators

		Fixed& operator=(const Fixed& other);
		friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
	
		// Comparisson operators

		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		// Arithmetic operators

		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		// In(de)crement postfix

		Fixed operator++(int);
		Fixed operator--(int);

		// In(de)crement prefix

		Fixed operator++();
		Fixed operator--();

		// Methods

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

		// Static Methods

		static const Fixed& min(const Fixed& current, const Fixed& other);
		static Fixed& min(Fixed& current, Fixed& other);
		static const Fixed& max(const Fixed& current, const Fixed& other);
		static Fixed& max(Fixed& current, Fixed& other);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif