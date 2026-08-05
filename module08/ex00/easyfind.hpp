/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 18:59:42 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/05 20:12:51 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm> // To use std::find
#include <exception> // To use std::exception

class NotFoundException : public std::exception
{
	public:
		const char* what() const throw() { return "Element not found in container";}
};

// std::find(begin, end, value) searches in [begin, end) and returns an iterator:
// - if found: iterator to the first matching element
// - if not found: end() iterator

// In a template, T::iterator depends on T, so we must write "typename T::iterator"
// to tell the compiler that T::iterator is a type.

// Example: 
// T == std::vector<int>;
// typename T::iterator == std::vector<int>::iterator

// Example with const:
// T == const std::list<int>
// typename T::const_iterator == std::list<int>::const_iterator


template<typename T>
typename T::iterator		easyfind(T& container, int n_toBeFound)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n_toBeFound);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

template<typename T>
typename T::const_iterator	easyfind(const T& container, int n_toBeFound)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), n_toBeFound);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

// Good practice to add the const version override as well

#endif