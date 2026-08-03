/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 19:18:37 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/03 19:37:02 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "colors.hpp"
#include <iostream>
#include <stdexcept> // For std::out_of_range

/*
 * Debug macro: activate by defining DEBUG during compilation
 * When DEBUG is defined, DBG_MSG(x) will print trace messages;
 * in normal compilation DBG_MSG is a no-op.
 * Example: 
 * - make debug 
 * - make -C ex00 debug
 */

#ifdef DEBUG
 # define DBG_MSG(x) std::cout << "Array " << x << std::endl
#else
 # define DBG_MSG(x) ((void)0)
#endif

// Constructors

template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0) {
	DBG_MSG("Default Constructor called");
}

template <typename T>
Array<T>::Array(unsigned int size) : _array(new T[size]), _size(size) {
	DBG_MSG("Default Constructor called");
}

template <typename T>
Array<T>::Array(const Array& src) {
	this->_array = new T[src._size];
	this->_size = src._size;

	for (unsigned int i = 0; i < src._size; i++)
		this->_array[i] = src._array[i];
	
	DBG_MSG("Copy Constructor called");
}

// Copy Assignment Operator

template <typename T>
Array<T>& Array<T>::operator=(const Array& src) {
	if (this != &src)
	{
		if (this->_array)
			delete[] this->_array;
		this->_array = new T[src._size];
		this->_size = src._size;

		for (unsigned int i = 0; i < src._size; i++)
			this->_array[i] = src._array[i];
	}
	DBG_MSG("Copy Assignment Operator called");
	return *this;
}

// Destructors

template <typename T>
Array<T>::~Array(void) {
	if (this->_array)
		delete[] this->_array;
	DBG_MSG("Destructor called");
}

// Getters

template <typename T>
unsigned int Array<T>::getSize() const {
	return (this->_size);
}

// Operators

template <typename T>
T& Array<T>::operator [] (unsigned int index) {
	if (index >= this->_size)
		throw std::out_of_range("Index out of range");
	return (this->_array[index]);
}

template <typename T>
const T& Array<T>::operator [] (unsigned int index) const {
	if (index >= this->_size)
		throw std::out_of_range("Index out of range");
	return (this->_array[index]);
}

// External method

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &array) {
	os << "[";
	for (unsigned int i = 0; i < array.getSize(); i++) {
		os << array[i];
		if (i < array.getSize() - 1)
			os << ", ";
	}
	os << "]";
	return (os);
}