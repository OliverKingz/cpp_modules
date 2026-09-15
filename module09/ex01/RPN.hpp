/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:25:10 by ozamora-          #+#    #+#             */
/*   Updated: 2026/09/15 17:25:51 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <iostream>
#include "colors.hpp"

class RPN
{
	public:
		RPN(void);
		RPN(const RPN& src);
		RPN& operator=(const RPN& src);
		~RPN(void);
};

#endif