/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 23:23:49 by upolat            #+#    #+#             */
/*   Updated: 2025/04/12 20:59:52 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <iomanip>
#include <chrono>
#include <sstream>
#include <string>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void parseCsv(std::string csvFile);
		void displayHoldings(std::string inputFile);
	private:
		std::map <int, double> _data;
		bool _isValidDate(const std::string &dateStr);
};