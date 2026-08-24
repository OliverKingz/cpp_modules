/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:04:44 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/24 18:43:46 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "colors.hpp"
#include <iostream>

/*
 * Debug macro: activate by defining DEBUG during compilation
 * When DEBUG is defined, DBG_MSG(x) will print trace messages;
 * in normal compilation DBG_MSG is a no-op.
 * Example: 
 * - make debug 
 * - make -C ex00 debug
 */

#ifdef DEBUG
 # define DBG_MSG(x) std::cout << "MutantStack " << x << std::endl
#else
 # define DBG_MSG(x) ((void)0)
#endif

template <typename T>
MutantStack<T>::MutantStack(void) {
	DBG_MSG("Default Constructor called");
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& src) : std::stack<T>(src) {
	DBG_MSG("Copy Constructor called");
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& src) {
	if (this != &src) {
		std::stack<T>::operator=(src);
	}
	DBG_MSG("Copy Assignment Operator called");
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(void) {
	DBG_MSG("Destructor called");
}

// Iterators

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (this->c.end());
}

// External operator overloads

template <typename T>
std::ostream& operator<<(std::ostream& out, const MutantStack<T>& other){
	typename MutantStack<T>::const_iterator it = other.begin();
	for (it = other.begin(); it != other.end(); ++it) {
		if (it != other.begin())
			out << ", ";
		out << *it;
	} 
	return (out);
}