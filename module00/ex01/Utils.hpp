/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:59:58 by ozamora-          #+#    #+#             */
/*   Updated: 2025/07/04 18:57:17 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# ifndef TEST
#  define TEST false
# endif

// Standard C++ Libraries

# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <cctype> 
# include <cstdlib> // To use exit()

// Color Definitions

# define RESET "\033[0m"
# define BOLD "\033[1m"
# define BOLD_OFF "\033[22m"
# define UNDERLINE "\033[4m"
# define UNDERLINE_OFF "\033[24m"
# define BLACK "\033[0;30m"
# define WHITE "\033[0;37m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"

// Utility Functions

bool stringToSizeT(const std::string &str, size_t &value);

bool isValidName(const std::string &name);
bool isValidPhoneNumber(const std::string &phoneNbr);

std::string inputName(const std::string &msg);
std::string inputPhoneNumber(const std::string &msg);
std::string inputString(const std::string &msg);

#endif
