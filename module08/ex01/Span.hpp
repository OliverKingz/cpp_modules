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
#include <iterator>
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

		std::vector<int>	getContainer(void) const;
		unsigned int		getMaxSize(void) const;

		void	addNumber(int n_toAdd);
		int		shortestSpan() const;
		int		longestSpan() const;

		// Template function to add a range of numbers to the Span
		// This function takes two iterators (begin and end) and adds the numbers in that range to the Span.
		// It is a template function, so it can work with any type of iterator (vector, list, etc)
		template <typename InputIterator>
		void	addNumber(InputIterator begin, InputIterator end)
		{
			size_t	distance = std::distance(begin, end);
			if (_container.size() + distance > _maxSize)
				throw (Span::maxSizeReachedException());
			_container.insert(_container.end(), begin, end);
		}

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

std::ostream& operator<<(std::ostream& os, const Span& span);

#endif