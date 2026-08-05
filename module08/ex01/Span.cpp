/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:02:35 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/05 19:02:36 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
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
 # define DBG_MSG(x) std::cout << "Span " << x << std::endl
#else
 # define DBG_MSG(x) ((void)0)
#endif

Span::Span(void) {
	DBG_MSG("Default Constructor called");
}

Span::Span(const Span& src) {
	DBG_MSG("Copy Constructor called");
}

Span& Span::operator=(const Span& src) {
	DBG_MSG("Copy Assignment Operator called");
}

Span::~Span(void) {
	DBG_MSG("Destructor called");
}