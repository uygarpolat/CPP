/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:32:50 by upolat            #+#    #+#             */
/*   Updated: 2025/04/10 17:24:02 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define GREEN "\033[32m"
#define DEFAULT "\033[39m"

int main(void) {
	try {
		std::cout << GREEN << "=== TEST 1 ===" << DEFAULT << std::endl;
		Span span(5);
		span.addNumber(1);
		span.addNumber(19);
		span.addNumber(32);
		span.addNumber(49);
		span.addNumber(61);
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << GREEN << "=== TEST 2 ===" << DEFAULT << std::endl;
		Span span2(5);
		std::vector<int> newData = {43, 65, -12, 107, 5};
	
		span2.addNumbers(newData);
		std::cout << span2.shortestSpan() << std::endl;
		std::cout << span2.longestSpan() << std::endl;
		span2.addNumber(101);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << GREEN << "=== TEST 3 ===" << DEFAULT << std::endl;
		Span span3(10000);
		std::vector<int> newData;
		newData.assign(10000, 42);
		span3.addNumber(101);
		span3.addNumbers(newData);
		std::cout << span3.shortestSpan() << std::endl;
		std::cout << span3.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << GREEN << "=== TEST 4 ===" << DEFAULT << std::endl;
		Span span4(10000);
		std::vector<int> newData;
		for (int i = 0; i < 10000; ++i) {
			newData.push_back(i);
		}
		span4.addNumbers(newData);
		std::cout << span4.shortestSpan() << std::endl;
		std::cout << span4.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << GREEN << "=== TEST 5 ===" << DEFAULT << std::endl;
		Span span5(2);
		span5.addNumber(std::numeric_limits<int>::max());
		span5.addNumber(std::numeric_limits<int>::min());

		std::cout << span5.shortestSpan() << std::endl;
		std::cout << span5.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}