/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 23:23:43 by upolat            #+#    #+#             */
/*   Updated: 2025/04/22 22:06:46 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	
	BitcoinExchange btc;
	try {
		if (argc < 2)
			throw std::runtime_error("Error: could not open file.");

		std::string csvFile = "data.csv";
		std::string inputFile = argv[1];
		
		btc.parseCsv(csvFile);
		btc.displayHoldings(inputFile);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}