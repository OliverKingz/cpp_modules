/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:02:35 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/06 17:43:30 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "colors.hpp"
#include <iostream>
#include <algorithm> // For std::sort

/*
 * Debug macro: activate by defining DEBUG during compilation
 * When DEBUG is defined, DBG_MSG(x) will print trace messages;
 * in normal compilation DBG_MSG is a no-op.
 * Example: 
 * - make debug 
 * - make -C ex00 debug
 */

#ifdef DEBUG
 # define DBG_MSG(x) std::cout << "Span " << x << std::endl
#else
 # define DBG_MSG(x) ((void)0)
#endif

Span::Span(void) : _maxSize(0) {
	DBG_MSG("Default Constructor called");
}

Span::Span(unsigned int maxSize) : _maxSize(maxSize){
	DBG_MSG("Size Constructor called");
}

Span::Span(const Span& src) : _container(src._container), _maxSize(src._maxSize){
	DBG_MSG("Copy Constructor called");
}

Span& Span::operator=(const Span& src) {
	if (this != &src)
	{
		_container = src._container;
		_maxSize = src._maxSize;
	}
	DBG_MSG("Copy Assignment Operator called");
	return (*this);
}

Span::~Span(void) {
	DBG_MSG("Destructor called");
}

/* ************************************************************************** */

void	Span::addNumber(int n_toAdd) {
	if (_container.size() >= _maxSize)
		throw (Span::maxSizeReachedException());
	_container.push_back(n_toAdd);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	size_t	distance = std::distance(begin, end);
	if (_container.size() + distance >= _maxSize)
		throw (Span::maxSizeReachedException());
	_container.insert(_container.end(), begin, end);
}

int		Span::shortestSpan() const {
	if (_container.size() < 2)
		throw (Span::unableToFindSpanException());

	// To find the shortest span, sort the container and then
	// find the min difference between consecutive elements.
	int shortestSpan;
	std::vector<int> sortedContainer = _container;
	std::sort(sortedContainer.begin(), sortedContainer.end());
	shortestSpan = sortedContainer[1] - sortedContainer[0];
	for (size_t i = 1; i < sortedContainer.size(); ++i) {
		int currentSpan = sortedContainer[i] - sortedContainer[i - 1];
		if (currentSpan < shortestSpan)
			shortestSpan = currentSpan;
	}
	return shortestSpan;
}

int		Span::longestSpan() const {
	if (_container.size() < 2)
		throw (Span::unableToFindSpanException());

	// To find the longest span, sort the container and then
	// find the difference between the first and last elements.
	int longestSpan;
	std::vector<int> sortedContainer = _container;
	std::sort(sortedContainer.begin(), sortedContainer.end());
	longestSpan = sortedContainer.back() - sortedContainer.front();
	return longestSpan;
}

/* ************************************************************************** */

const char* Span::unableToFindSpanException::what() const throw() {
	return ("Span Exception: unable to find the span");
}

const char* Span::maxSizeReachedException::what() const throw() {
	return ("Span Exception: unable to add more numbers, the container is full");
}