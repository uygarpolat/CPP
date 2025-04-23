/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 23:23:46 by upolat            #+#    #+#             */
/*   Updated: 2025/04/23 23:50:20 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _data() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_data = other._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::parseCsv(std::string csvFile) {
	
	std::ifstream file(csvFile);
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
			
	std::string line;
	while (std::getline(file, line)) {
		try {
			std::string date = line.substr(0, line.find(','));
			if (!_isValidDate(date))
				throw std::runtime_error("Error: bad input => " + date);
			// replace all '-' with empty string, super fancy
			date.erase(std::remove(date.begin(), date.end(), '-'), date.end());
			int dateInt = stoi(date);

			std::string rateStr = line.substr(line.find(',') + 1);

			// trim leading and trailing whitespace
			rateStr.erase(0, rateStr.find_first_not_of(" \t"));
			rateStr.erase(rateStr.find_last_not_of(" \t") + 1);
			
			// if rateStr has non-numeric characters (except a decimal point),
			// or if there are more than one decimal point, we throw an error
			if (rateStr.find_first_not_of("0123456789.") != std::string::npos ||
				rateStr.find('.') != rateStr.rfind('.'))
				throw std::runtime_error("Error: bad input => " + rateStr);
			
			double rate = stod(rateStr);
			
			_data[dateInt] = rate;
		}
		catch (std::exception &e) {
			continue;
		}		
	}
	file.close();
}

void BitcoinExchange::displayHoldings(std::string inputFile) {
	
	std::ifstream file(inputFile);
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
		
	std::string amountStr = "";
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
		throw std::runtime_error("Error: invalid file header");
		
	while (std::getline(file, line)) {
		try {
				
			std::string date = line.substr(0, line.find('|'));
			if (!_isValidDate(date))
				throw std::runtime_error("Error: bad input => " + date);
			std::string dateBackup = date;
			// replace all '-' with empty string, super fancy
			date.erase(std::remove(date.begin(), date.end(), '-'), date.end());
			int dateInt = stoi(date);

			int beginningOfHistoricalData = _data.begin()->first;
			int endOfHistoricalData = _data.rbegin()->first;
			
			if (dateInt > endOfHistoricalData)
				dateInt = endOfHistoricalData;
				
			while (dateInt >= beginningOfHistoricalData) {
				if (_data.contains(dateInt))
					break;
				else
					--dateInt;
			}

			if (dateInt < beginningOfHistoricalData)
				throw std::runtime_error("Error: historical data not found => " + dateBackup);

			amountStr = line.substr(line.find('|') + 1);

			// trim leading and trailing whitespace
			amountStr.erase(0, amountStr.find_first_not_of(" \t"));
			amountStr.erase(amountStr.find_last_not_of(" \t") + 1);
			
			// if amountStr has non-numeric characters (except a decimal point),
			// or if there are more than one decimal point, we throw an error
			if (amountStr.find_first_not_of("0123456789.") != std::string::npos ||
				amountStr.find('.') != amountStr.rfind('.'))
				throw std::runtime_error("Error: bad input => " + amountStr);
			
			double amount = stod(amountStr);

			if (amount <= 0)
				throw std::runtime_error("Error: not a positive number.");
			if (amount >= 1000)
				throw std::runtime_error("Error: too large a number.");

			std::cout << dateBackup << "=> " << amount << " = " << amount * _data[dateInt] << std::endl;
		}
		catch (const std::invalid_argument& e) {
			std::cout << "Error: bad input =>" << amountStr << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	file.close();
}

bool BitcoinExchange::_isValidDate(const std::string &dateStr) {
	
    std::istringstream in{dateStr};
    std::tm t = {};

	// We try to parse the date in this format: YYYY-MM-DD. If unsuccessful, we abort.
	in >> std::get_time(&t, "%Y-%m-%d");
    if (in.fail())
        return false;
    
	// Needs some conversion, because chrono and tm uses different standards.
    std::chrono::year_month_day ymd{
        std::chrono::year{t.tm_year + 1900},
        std::chrono::month{static_cast<unsigned int>(t.tm_mon + 1)},
        std::chrono::day{static_cast<unsigned int>(t.tm_mday)}
    };
    return ymd.ok();
}
