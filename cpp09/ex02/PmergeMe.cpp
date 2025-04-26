/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:12:18 by upolat            #+#    #+#             */
/*   Updated: 2025/04/27 00:10:23 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _containerVector(), _containerDeque() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _containerVector(other._containerVector), _containerDeque(other._containerDeque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_containerVector = other._containerVector;
		_containerDeque = other._containerDeque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::getContainerVector() {
	return _containerVector;
}

std::deque<int> PmergeMe::getContainerDeque() {
	return _containerDeque;
}

uint64_t PmergeMe::getJacobsthal(size_t n){
	uint64_t pow2 = 1ULL << n;
	int64_t sign = (n & 1) ? -1 : +1;
	return (pow2 - sign) / 3;
}

PmergeMe::PmergeMe(int argc, char **argv) {

	int num;
	
	for (int i = 1; i < argc; ++i) {
	
		std::string arg(argv[i]);

		try {
			num = std::stoi(arg);
		}
		catch (std::exception &e) {
			throw std::invalid_argument("Error: Invalid input: " + arg);
		}
		if (num <= 0)
			throw std::invalid_argument("Error: Non-positive number: " + arg);

		if (arg.find_first_not_of("0123456789") != std::string::npos)
			throw std::invalid_argument("Error: Invalid input: " + arg);

		_containerVector.push_back(num);
		_containerDeque.push_back(num);
	}
}
