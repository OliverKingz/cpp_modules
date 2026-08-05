/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:04:44 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/05 19:04:58 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
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
 # define DBG_MSG(x) std::cout << "MutantStack " << x << std::endl
#else
 # define DBG_MSG(x) ((void)0)
#endif

MutantStack::MutantStack(void) {
	DBG_MSG("Default Constructor called");
}

MutantStack::MutantStack(const MutantStack& src) {
	DBG_MSG("Copy Constructor called");
}

MutantStack& MutantStack::operator=(const MutantStack& src) {
	DBG_MSG("Copy Assignment Operator called");
}

MutantStack::~MutantStack(void) {
	DBG_MSG("Destructor called");
}