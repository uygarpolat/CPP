/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:12:18 by upolat            #+#    #+#             */
/*   Updated: 2025/04/20 03:16:10 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int PmergeMe::comparisons = 0;

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
			throw std::invalid_argument("Error: Non-positive integer: " + arg);

		_containerVector.push_back(num);
		_containerDeque.push_back(num);
	}
}
