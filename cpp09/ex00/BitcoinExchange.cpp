/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 23:23:46 by upolat            #+#    #+#             */
/*   Updated: 2025/04/11 23:24:04 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : data(0) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : data(other.data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		data = other.data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}