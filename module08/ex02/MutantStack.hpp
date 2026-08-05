/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:04:29 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/05 19:04:39 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "colors.hpp"

class MutantStack
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack& src);
		MutantStack& operator=(const MutantStack& src);
		~MutantStack(void);
};