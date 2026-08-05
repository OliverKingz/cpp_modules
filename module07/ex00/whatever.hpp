/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 19:18:05 by ozamora-          #+#    #+#             */
/*   Updated: 2026/08/05 20:18:56 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T> void swap(T& a, T& b) // Use & to avoid copies
{
	T aux = a;
	a = b;
	b = aux;
};

template<typename T> const T& min(const T& a, const T& b) // Use const to not change values
{
	return (a < b) ? a : b;
};

template <typename T> const T& max(const T& a, const T& b)
{
	return (a > b) ? a : b;
};

#endif