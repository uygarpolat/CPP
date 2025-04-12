/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 23:23:43 by upolat            #+#    #+#             */
/*   Updated: 2025/04/12 14:05:07 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

int main(void) {
	
	BitcoinExchange bitcoinExchange;
	try {
		bitcoinExchange.parseCsv();
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	std::map<int, double> data = bitcoinExchange.getData();
	for (const auto &pair : data) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	}



	return 0;
}