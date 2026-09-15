/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:25:10 by ozamora-          #+#    #+#             */
/*   Updated: 2026/09/15 21:37:00 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <stack>

// Reverse Polish Notation (RPN)
// Example: 
//	Input: "3 4 + 2 * 7 /"
//	Equivalent to: "((3 + 4) * 2) / 7"
class RPN
{
	private:
		std::stack<int> _stack;

		void doOperation(char op);

	public:
		RPN(void);
		RPN(const RPN& src);
		RPN& operator=(const RPN& src);
		~RPN(void);

		int calculateRPN(const std::string& input);
};

bool isOperator(char c);

#endif