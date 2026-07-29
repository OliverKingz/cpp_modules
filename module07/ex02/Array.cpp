/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 19:18:37 by ozamora-          #+#    #+#             */
/*   Updated: 2026/07/29 19:18:38 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
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
 # define DBG_MSG(x) std::cout << "Array " << x << std::endl
#else
 # define DBG_MSG(x) ((void)0)
#endif

Array::Array(void) {
	DBG_MSG("Default Constructor called");
}

Array::Array(const Array& src) {
	DBG_MSG("Copy Constructor called");
}

Array& Array::operator=(const Array& src) {
	DBG_MSG(<< "Copy Assignment Operator called");
}

Array::~Array(void) {
	DBG_MSG("Destructor called");
}