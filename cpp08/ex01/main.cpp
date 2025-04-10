/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:32:50 by upolat            #+#    #+#             */
/*   Updated: 2025/04/10 20:34:55 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void) {
	try {
		std::cout << GREEN << "=== TEST 1 ===" << DEFAULT << std::endl;
		std::cout << "Testing filling the container" << DEFAULT << std::endl;
		Span span(5);
		span.addNumber(1);
		span.addNumber(19);
		span.addNumber(32);
		span.addNumber(49);
		span.addNumber(61);
		span.printContainer();
		std::cout << BLUE << "Shortest span: " << DEFAULT << span.shortestSpan() << std::endl;
		std::cout << BLUE << " Longest span: " << DEFAULT << span.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	try {
		std::cout << GREEN << "\n===== TEST 2 =====" << DEFAULT << std::endl;
		std::cout << "Testing filling the container and then trying to overfill it" << DEFAULT << std::endl;
		Span span2(5);
		std::vector<int> newData = {43, 65, -12, 107, 5};
	
		span2.addNumbers(newData);
		span2.printContainer();
		std::cout << BLUE << "Shortest span: " << DEFAULT << span2.shortestSpan() << std::endl;
		std::cout << BLUE << " Longest span: " << DEFAULT << span2.longestSpan() << std::endl;
		span2.addNumber(101);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	try {
		std::cout << GREEN << "\n===== TEST 3 =====" << DEFAULT << std::endl;
		std::cout << "Testing filling the container with 10000 42s, and then trying to overfill it" << DEFAULT << std::endl;
		Span span3(10000);
		std::vector<int> newData;
		newData.assign(10000, 42);
		span3.addNumbers(newData);
		std::cout << BLUE << "Shortest span: " << DEFAULT << span3.shortestSpan() << std::endl;
		std::cout << BLUE << " Longest span: " << DEFAULT << span3.longestSpan() << std::endl;
		span3.addNumber(101);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	try {
		std::cout << GREEN << "\n===== TEST 4 =====" << DEFAULT << std::endl;
		std::cout << "Testing filling the container with 10000 numbers from 0 to 9999" << DEFAULT << std::endl;
		Span span4(10000);
		std::vector<int> newData;
		for (int i = 0; i < 10000; ++i)
			newData.push_back(i);
		span4.addNumbers(newData);
		std::cout << BLUE << "Shortest span: " << DEFAULT << span4.shortestSpan() << std::endl;
		std::cout << BLUE << " Longest span: " << DEFAULT << span4.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	try {
		std::cout << GREEN << "\n===== TEST 5 =====" << DEFAULT << std::endl;
		std::cout << "Testing with int_max, int_min and zero values" << std::endl;
		Span span5(3);
		span5.addNumber(std::numeric_limits<int>::max());
		span5.addNumber(std::numeric_limits<int>::min());

		span5.printContainer();
		std::cout << BLUE << "Shortest span: " << DEFAULT << span5.shortestSpan() << std::endl;
		std::cout << BLUE << " Longest span: " << DEFAULT << span5.longestSpan() << std::endl;
		
		span5.addNumber(0);
		span5.printContainer();
		std::cout << BLUE << "Shortest span: " << DEFAULT << span5.shortestSpan() << std::endl;
		std::cout << BLUE << " Longest span: " << DEFAULT << span5.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	try {
		std::cout << GREEN << "\n===== TEST 6 =====" << DEFAULT << std::endl;
		std::cout << "Testing overflowing a partially filled container" << std::endl;
		Span span6(10);
		span6.addNumber(1);
		span6.addNumber(2);
		span6.addNumber(3);

		std::vector<int> newData = {4, 5, 6, 7, 8, 9, 10, 11};
		span6.addNumbers(newData);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	try {
		std::cout << GREEN << "\n===== TEST 7 =====" << DEFAULT << std::endl;
		std::cout << "Testing with an empty container" << std::endl;
		Span span7(0);
		span7.printContainer();
		std::cout << BLUE << "Shortest span: " << DEFAULT << span7.shortestSpan() << std::endl;
		std::cout << BLUE << " Longest span: " << DEFAULT << span7.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	try {
		std::cout << GREEN << "\n===== TEST 8 =====" << DEFAULT << std::endl;
		std::cout << "Testing spans with 10 random numbers" << std::endl;
		srand(static_cast<unsigned int>(time(0)));
		Span span8(10);
		std::vector<int> newData;
		for (int i = 0; i < 10; ++i)
			newData.push_back(rand() % 100);
		span8.addNumbers(newData);
		span8.printContainer();
		std::cout << BLUE << "Shortest span: " << DEFAULT << span8.shortestSpan() << std::endl;
		std::cout << BLUE << " Longest span: " << DEFAULT << span8.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	try {
		std::cout << GREEN << "\n===== TEST 9 =====" << DEFAULT << std::endl;
		std::cout << "Testing spans with 10000 random numbers" << std::endl;
		srand(static_cast<unsigned int>(time(0)));
		Span span8(10000);
		std::vector<int> newData;
		for (int i = 0; i < 10000; ++i)
			newData.push_back(rand() % 1000000);
		span8.addNumbers(newData);
		std::cout << BLUE << "Shortest span: " << DEFAULT << span8.shortestSpan() << std::endl;
		std::cout << BLUE << " Longest span: " << DEFAULT << span8.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	
	return 0;
}