/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:23:07 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/05 19:01:33 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
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
 # define DBG_MSG(x) std::cout << "Serializer " << x << std::endl
#else
 # define DBG_MSG(x) ((void)0)
#endif

/* ************************************************************************** */

Serializer::Serializer(void) {
	DBG_MSG("Default Constructor called");
}

Serializer::Serializer(const Serializer& src) {
	(void)src;
	DBG_MSG("Copy Constructor called");
}

Serializer& Serializer::operator=(const Serializer& src) {
	(void)src;
	DBG_MSG("Copy Assignment Operator called");
	return (*this);
}

Serializer::~Serializer(void) {
	DBG_MSG("Destructor called");
}

/* ************************************************************************** */

uintptr_t Serializer::serialize(Data *ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data*>(raw));
}

/* ************************************************************************** */