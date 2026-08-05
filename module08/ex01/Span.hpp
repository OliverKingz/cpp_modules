/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:00:18 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/05 19:00:18 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "colors.hpp"

class Span
{
	public:
		Span(void);
		Span(const Span& src);
		Span& operator=(const Span& src);
		~Span(void);
};