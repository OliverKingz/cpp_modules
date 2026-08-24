/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:04:29 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/24 19:02:43 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

/*
Stack is a container adaptor that gives the functionality of LIFO (last-in, first-out) data structure.
Queue and deque are other container adaptors that operate in a FIFO context (first-in, first-out).

Stack only allows access to the top element, and does not provide iterators to traverse the elements.
Usage: 
- top() to access the top element
- push() to add an element
- pop() to remove the top element
- empty() to check if the stack is empty.
- size() to get the number of elements in the stack.
Stack doesn't allow iteration through its elements. 
With MutantStack, we can iterate through the elements of the stack using iterators.
The begin() and end() methods are needed to provide access to
the underlying container's iterators, allowing us to iterate through the elements of the stack.
*/
template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack& src);
		MutantStack& operator=(const MutantStack& src);
		~MutantStack(void);

		// Iterator

		typedef typename std::stack<T>::container_type::iterator		iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
		
		iterator begin();
		iterator end();

		const_iterator begin() const;
		const_iterator end() const;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const MutantStack<T>& other);

#include "MutantStack.tpp"

#endif