/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 23:23:46 by upolat            #+#    #+#             */
/*   Updated: 2025/04/12 14:08:49 by upolat           ###   ########.fr       */
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

void BitcoinExchange::parseCsv() {
	
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file");
		
	std::string line;
	while (std::getline(file, line)) {
		try {
			std::string date = line.substr(0, line.find(','));
			// Replace all '-' with empty string
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

std::map<int, double> BitcoinExchange::getData() const {
	return _data;
}
