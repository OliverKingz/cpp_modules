/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:25:02 by ozamora-          #+#    #+#             */
/*   Updated: 2026/09/15 17:26:25 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
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
 # define DBG_MSG(x) std::cout << "RPN " << x << std::endl
#else
 # define DBG_MSG(x) ((void)0)
#endif

RPN::RPN(void) {
	DBG_MSG("Default Constructor called");
}

RPN::RPN(const RPN& src) {
	DBG_MSG("Copy Constructor called");
}

RPN& RPN::operator=(const RPN& src) {
	DBG_MSG("Copy Assignment Operator called");
}

RPN::~RPN(void) {
	DBG_MSG("Destructor called");
}