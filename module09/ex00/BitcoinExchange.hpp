/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:19:27 by ozamora-          #+#    #+#             */
/*   Updated: 2026/09/15 20:21:06 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _dataBTCexchangeRates;
	

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange(void);

		void parseDataFile(const std::string& dataFilename);
		void processInputFile(const std::string& inputFilename);
		void getExchangeAndPrint(const std::string& date, double value);
};

bool isLeapYear(int year);
bool isValidDate(const std::string& date);

#endif