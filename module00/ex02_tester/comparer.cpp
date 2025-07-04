/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raperez- <raperez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:12:28 by raperez-          #+#    #+#             */
/*   Updated: 2025/07/01 15:54:46 by raperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string.h>

static	std::string skip_time(const std::string& str)
{
	int			ind = 0;
	std::string	new_str;

	while (str[ind] && str[ind] != ']')
		ind++;
	if (!str[ind])
		return (str);
	new_str = str.substr(ind + 1);
	return (new_str);
}

int main(void)
{
	std::ifstream   my_log;
	std::ifstream   subj_log;
	std::string		my_str, subj_str;
	int				i;

	my_log.open("my.log");
	if (!my_log.is_open())
	{
		std::cout << "Error opening my.log";
		return (1);
	}
	subj_log.open("subject.log");
	if (!subj_log.is_open())
	{
		std::cout << "Error opening subject.log";
		return (1);
	}
	my_log >> my_str;
	subj_log >> subj_str;
	i = 1;
	while (my_str != "x" && subj_str != "x")
	{
		my_str = skip_time(my_str);
		subj_str = skip_time(subj_str);
		if (my_str != subj_str)
		{
			std::cout << "\033[1;31mError: line " << i/2 << " is different\033[0m\n";
			std::cout << "my.log:\t\t" << my_str << std::endl;
			std::cout << "subject.log:\t" << subj_str << std::endl;
		}
		my_log >> my_str;
		subj_log >> subj_str;
		i++;
	}
	if (my_str != subj_str)
		std::cout << "\033[1;31mError: line " << i << " is different\033[0m\n";
	return (0);
}
