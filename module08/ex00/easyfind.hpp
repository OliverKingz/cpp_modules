/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 18:59:42 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/05 19:00:11 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "colors.hpp"

class easyfind
{
	public:
		easyfind(void);
		easyfind(const easyfind& src);
		easyfind& operator=(const easyfind& src);
		~easyfind(void);
};