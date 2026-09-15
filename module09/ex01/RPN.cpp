/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:25:02 by ozamora-          #+#    #+#             */
/*   Updated: 2026/09/15 21:37:37 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "colors.hpp"

#include <iostream> // To use std::cout
#include <stdexcept> // To use std::runtime_error
#include <cctype> // To use std::isspace and std::isdigit
#include <climits> // To use INT_MAX and INT_MIN

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

RPN::RPN(const RPN& src) : _stack(src._stack) {
	DBG_MSG("Copy Constructor called");
}

RPN& RPN::operator=(const RPN& src) {
	DBG_MSG("Copy Assignment Operator called");
	if (this != &src) {
		_stack = src._stack;
	}
	return *this;
}

RPN::~RPN(void) {
	DBG_MSG("Destructor called");
}

/* ************************************************************************** */

bool isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

/* ************************************************************************** */

void RPN::doOperation(char op) {
	int A;
	int B;
	long long result;

	B = _stack.top();
	_stack.pop();
	A = _stack.top();
	_stack.pop();
	switch (op) {
		case '+':
			result = static_cast<long long>(A) + B;
			break;
		case '-':
			result = static_cast<long long>(A) - B;
			break;
		case '*':
			result = static_cast<long long>(A) * B;
			break;
		case '/':
			if (B == 0)
				throw std::runtime_error("Error");
			result = static_cast<long long>(A) / B;
			break;
	}
	if (result > INT_MAX || result < INT_MIN)
		throw std::runtime_error("Error");
	_stack.push(static_cast<int>(result));
}

/* ************************************************************************** */

int RPN::calculateRPN(const std::string& input) {
	// Clear the stack before starting the calculation
	while (!_stack.empty())
		_stack.pop();

	// Process each character in the input string
	for(unsigned int i = 0; i < input.length(); i++)
	{
		char c = input[i];

		// Skip whitespace characters
		if (std::isspace(c)){
			continue;
		}

		// If c is a digit, push it onto the stack
		// If c is an operator, perform the operation
		// If c is neither, throw an error
		if (std::isdigit(c)) {
			_stack.push(c - '0');
		}
		else if (isOperator(c)){
			if (_stack.size() < 2)
				throw std::runtime_error("Error");
			doOperation(c);
		}
		else
			throw std::runtime_error("Error");
	}

	// After processing the input, there should be exactly one value left on the stack
	if (_stack.size() != 1)
		throw std::runtime_error("Error");
	return _stack.top();
}

/* ************************************************************************** */