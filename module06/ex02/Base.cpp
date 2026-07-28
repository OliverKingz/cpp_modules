/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 18:54:22 by ozamora-          #+#    #+#             */
/*   Updated: 2026/07/28 19:42:51 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "colors.hpp"
#include <cstdlib> // To use rand

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

/* ************************************************************************** */

Base::Base(void) {
	DBG_MSG("Base Default Constructor called");
}

Base::~Base(void) {
	DBG_MSG("Base Destructor called");
}

/* ************************************************************************** */

A::A(void) {
	std::cout << "Default Constructor called for A" << std::endl;
}

/* ************************************************************************** */

B::B(void) {
	std::cout << "Default Constructor called for B" << std::endl;
}

/* ************************************************************************** */

C::C(void) {
	std::cout << "Default Constructor called for C" << std::endl;
}

/* ************************************************************************** */

Base * generate(void)
{
	int randNum = std::rand() % 3;

	if ( randNum == 0 )
		return new A();
	else if ( randNum == 1 )
		return new B();
	else
		return new C(); 
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "The object is A (ptr)" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "The object is B (ptr)" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "The object is C (ptr)" << std::endl;
	else
		std::cout << "The object is Unknown (ptr)" << std::endl;
}

void identify(Base& p)
{
	try {
		(void)(dynamic_cast<A&>(p)); // (void) to avoid the warning unused-value
		std::cout << "The object is A (ref)" << std::endl;
		return ;
	} catch (std::exception&){}

	try {
		(void)(dynamic_cast<B&>(p));
		std::cout << "The object is B (ref)" << std::endl;
		return ;
	} catch (std::exception&){}

	try {
		(void)(dynamic_cast<C&>(p));
		std::cout << "The object is C (ref)" << std::endl;
		return ;
	} catch (std::exception&){}

	std::cout << "The object is Unknown (ref)" << std::endl;
}

/* ************************************************************************** */
