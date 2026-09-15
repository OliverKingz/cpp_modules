/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:19:31 by ozamora-          #+#    #+#             */
/*   Updated: 2026/09/15 20:21:21 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "colors.hpp"

#include <iostream> // To use std::cout, std::cerr, std::endl
#include <string> // To use std::string, c_str
#include <fstream> // To use std::ifstream
#include <map> // To use std::map
#include <sstream> // To use std::stringstream
#include <cstdlib> // To use std::strtod
#include <stdexcept> // To use std::runtime_error

/*
 * Debug macro: activate by defining DEBUG during compilation
 * When DEBUG is defined, DBG_MSG(x) will print trace messages;
 * in normal compilation DBG_MSG is a no-op.
 * Example: 
 * - make debug 
 * - make -C ex00 debug
 */

#ifdef DEBUG
 # define DBG_MSG(x) std::cout << "BitcoinExchange " << x << std::endl
#else
 # define DBG_MSG(x) ((void)0)
#endif

BitcoinExchange::BitcoinExchange(void) {
	DBG_MSG("Default Constructor called");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
	DBG_MSG("Copy Constructor called");
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {
	DBG_MSG("Copy Assignment Operator called");
	if (this != &src)
		this->_dataBTCexchangeRates = src._dataBTCexchangeRates;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void) {
	DBG_MSG("Destructor called");
}

/* ************************************************************************** */

void BitcoinExchange::parseDataFile(const std::string& dataFilename) {
	DBG_MSG("parseDataFile called");

	std::ifstream	dataFile(dataFilename.c_str());
	if (!dataFile.is_open())
		throw std::runtime_error(RED "Error: " RESET "could not open data file: " + dataFilename);

	std::string		line;
	std::string		date;
	std::string		valueStr;
	double			value;
	char 			delim = ',';
	size_t			delimPos;

	// Header line check
	if (!std::getline(dataFile, line) || line != "date,exchange_rate")
		throw std::runtime_error(RED "Error: " RESET "invalid header in data file");

	// Parse each line in the data file
	while (std::getline(dataFile, line)) {
		if (line.empty())
			continue;

		// Split the line into date and value using the delimiter
		delimPos = line.find(delim);
		if (delimPos == std::string::npos)
			throw std::runtime_error(RED "Error: " RESET "invalid line format in data file: " + line);
		date = line.substr(0, delimPos);
		valueStr = line.substr(delimPos + 1);

		// Check if the date is valid and convert the value to double
		if (!isValidDate(date))
			throw std::runtime_error(RED "Error: " RESET "invalid date in data file: " + date);
		char *endPtr;
		value = std::strtod(valueStr.c_str(), &endPtr);
		if (endPtr == valueStr.c_str() || *endPtr != '\0')
			throw std::runtime_error(RED "Error: " RESET "invalid value in data file: " + valueStr);
		
		// Store the date and value in the map
		_dataBTCexchangeRates[date] = value;
	}
	dataFile.close();
}

void BitcoinExchange::processInputFile(const std::string& inputFilename) {
	DBG_MSG("processInputFile called");

	std::ifstream	inputFile(inputFilename.c_str());
	if (!inputFile.is_open())
		throw std::runtime_error(RED "Error: " RESET "could not open input file: " + inputFilename);

	std::string		line;
	std::string		date;
	std::string		valueStr;
	double			value;
	std::string		delim = " | ";
	size_t			delimPos;

	// Header line check
	if (!std::getline(inputFile, line) || line != "date | value")
		throw std::runtime_error(RED "Error: " RESET "invalid header in input file");

	// Process each line in the input file
	while (std::getline(inputFile, line)) {
		if (line.empty())
			continue;

		// Split the line into date and value using the delimiter " | "
		delimPos = line.find(delim);
		if (delimPos == std::string::npos) {
			std::cerr << RED "Error: " RESET "bad input => " << line << std::endl;
			continue;
		}
		date = line.substr(0, delimPos);
		valueStr = line.substr(delimPos + 3);

		// Check if the date is valid and convert the value to double
		if (!isValidDate(date)) {
			std::cerr << RED "Error: " RESET "bad input => " << line << std::endl;
			continue;
		}

		char *endPtr;
		value = std::strtod(valueStr.c_str(), &endPtr);
		if (endPtr == valueStr.c_str() || *endPtr != '\0' || value != value) {
			std::cerr << RED "Error: " RESET "bad input, invalid value => " << line << std::endl;
			continue;
		}

		// Check if the value is positive and not too large
		if (value < 0){
			std::cerr << RED "Error: " RESET "not a positive number." << std::endl;
			continue;
		}
		if (value > 1000){ // Arbitrary limit for "too large" value
			std::cerr << RED "Error: " RESET "too large a number." << std::endl;
			continue;
		}

		// Get the exchange rate and print the result
		getExchangeAndPrint(date, value);
	}
	inputFile.close();
}

void BitcoinExchange::getExchangeAndPrint(const std::string& date, double value) {
	double exchange = 0.0;

	// Find the closest date in the map that is less than or equal to the input date
	// lower_bound returns an iterator to the first element that is not less than the given key
	std::map<std::string, double>::iterator it = _dataBTCexchangeRates.lower_bound(date);

	// If the exact date is found, use its exchange rate; otherwise, use the previous date's rate
	if (it != _dataBTCexchangeRates.end() && it->first == date) {
		exchange = value * it->second;
		std::cout << date << " => " << value << " = " << exchange << std::endl;
	} else if (it != _dataBTCexchangeRates.begin()) {
		--it;
		exchange = value * it->second;
		std::cout << date << " => " << value << " = " << exchange << std::endl;
	} else {
		std::cerr << RED "Error: " RESET "no exchange rate available for the given date: " << date << std::endl;
	}
}

/* ************************************************************************** */

// For a year to be a leap year, it must satisfy the following conditions:
// 1. The year is divisible by 4 but not divisible by 100
//    Example: 2004, 2024 are leap years, but 2100, 2200, 2300 are not
// 2. The year is divisible by 400 (as it is divisible by 4 and 100)
//    Example: 1600, 2000, 2400 are leap years, but 1700, 1800, 1900 are not
bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || ( year % 400 == 0);
}

bool isValidDate(const std::string& date)
{
	// Date format example: 2010-12-31

	// Check if the date format is correct (YYYY-MM-DD)
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	
	int year;
	int month;
	int day;
	char dash1;
	char dash2;

	std::stringstream ss(date);
	if (!(ss >> year >> dash1 >> month >> dash2 >> day) || !(ss.eof()))
		return false;

	if (dash1 != '-' || dash2 != '-')
		return false;
	
	// There were no btc before 2009, and the month and day must be valid
	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	
	static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int maxDays = daysInMonth[month - 1];
	if (month == 2 && isLeapYear(year))
		maxDays = 29;
	
	return day <= maxDays;
}