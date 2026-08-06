/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:00:18 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/05 19:00:18 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <string>
#include <iostream>
#include <exception>
#include <vector>

class Span
{
	private:
		std::vector<int>	_container;
		unsigned int		_maxSize;
	public:
		Span(void);
		Span(unsigned int size);
		Span(const Span& src);
		Span& operator=(const Span& src);
		~Span(void);

		void	addNumber(int n_toAdd);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan() const;
		int		longestSpan() const;

	class unableToFindSpanException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class maxSizeReachedException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

#endif