/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 19:04:29 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/05 20:17:51 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

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

#endif