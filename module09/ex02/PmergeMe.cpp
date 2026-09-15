/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:29:05 by ozamora-          #+#    #+#             */
/*   Updated: 2026/09/15 17:30:07 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
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
 # define DBG_MSG(x) std::cout << "PmergeMe " << x << std::endl
#else
 # define DBG_MSG(x) ((void)0)
#endif

PmergeMe::PmergeMe(void) {
	DBG_MSG("Default Constructor called");
}

PmergeMe::PmergeMe(const PmergeMe& src) {
	DBG_MSG("Copy Constructor called");
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
	DBG_MSG("Copy Assignment Operator called");
}

PmergeMe::~PmergeMe(void) {
	DBG_MSG("Destructor called");
}