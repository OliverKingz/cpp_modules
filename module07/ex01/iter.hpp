/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 19:18:25 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/03 19:05:11 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "colors.hpp"

/*
 * Debug macro: activate by defining DEBUG during compilation
 * When DEBUG is defined, DBG_MSG(x) will print trace messages;
 * in normal compilation DBG_MSG is a no-op.
 * Example: 
 * - make debug 
 * - make -C ex00 debug
 */

#ifdef DEBUG
 # define DBG_MSG(x) std::cout << x << std::endl
#else
 # define DBG_MSG(x) ((void)0)
#endif

// Overload for const arrays: chosen when you pass const T*.
// Elements are treated as const T, so callbacks should accept const T&.
// If a callback expects T& (non-const), it will NOT match this overload.
// For simplicity, you can choose to only have this overload if read-only access is enough
template<typename T, typename F>
void iter(const T* array, size_t length, F funct)
{
	for (size_t i = 0; i < length; ++i)
		funct(array[i]);
	DBG_MSG("(used iter const overload)");
}; 

// Overload for non-const arrays: chosen when you pass T*.
// Elements are T and passed as T&. Callbacks can be T& or const T&.
// Use this overload when you need to modify elements inside the callback.
template<typename T, typename F>
void iter(T* array, size_t lenght, F funct)
{
	for (size_t i = 0; i < lenght; i++)
		funct(array[i]);
	DBG_MSG("(used iter non-const overload)");
};

/* ************************************************************************** */

// Read-only version. Accepts both const and non-const arrays.
// Preferred: read-only version. Accepts both const and non-const arrays.
// If you add a non-const overload void printElement(T&), the unqualified name
// printElement<T> becomes ambiguous when passed to iter. Use a cast or a lambda
// to select the exact overload (or use different function names).
template<typename T>
void printElement(const T& element)
{
	std::cout << element << ", ";
};

// The write version (non-const) is commented out to avoid ambiguity when calling iter with printElement.
// template<typename T>
// void printElement(T& element)
// {
// 	std::cout << element << std::endl;
// };

/* ************************************************************************** */

// Write version: modifies elements. Accepts only non-const arrays.
template<typename T>
void setElement42(T& element)
{
	element = 42;
};