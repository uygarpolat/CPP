/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 23:23:46 by upolat            #+#    #+#             */
/*   Updated: 2025/04/12 15:29:08 by upolat           ###   ########.fr       */
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
		throw std::runtime_error("Error: could not open file");
		
	std::string line;
	while (std::getline(file, line)) {
		try {
			std::string date = line.substr(0, line.find(','));
			if (!_isValidDate(date))
				throw std::runtime_error("Error: bad input => " + date);
			// replace all '-' with empty string, super fancy
			date.erase(std::remove(date.begin(), date.end(), '-'), date.end());
			int dateInt = std::stoi(date);
			double value = stod(line.substr(line.find(',') + 1));
			_data[dateInt] = value;
		}
		catch (std::exception &e) {
			continue;
		}		
	}
	file.close();
}

void BitcoinExchange::displayHoldings(std::string inputFile) {
	(void)inputFile;
}

std::map<int, double> BitcoinExchange::getData() const {
	return _data;
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