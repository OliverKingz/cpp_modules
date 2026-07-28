/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 16:02:04 by ozamora-          #+#    #+#             */
/*   Updated: 2026/07/28 16:13:18 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "colors.hpp"

class Base
{
	public:
		virtual ~Base(void);
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);