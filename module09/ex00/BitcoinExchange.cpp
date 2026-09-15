/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:19:31 by ozamora-          #+#    #+#             */
/*   Updated: 2026/09/15 17:21:43 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
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
 # define DBG_MSG(x) std::cout << "BitcoinExchange " << x << std::endl
#else
 # define DBG_MSG(x) ((void)0)
#endif

BitcoinExchange::BitcoinExchange(void) {
	DBG_MSG("Default Constructor called");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
	DBG_MSG("Copy Constructor called");
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {
	DBG_MSG("Copy Assignment Operator called");
}

BitcoinExchange::~BitcoinExchange(void) {
	DBG_MSG("Destructor called");
}