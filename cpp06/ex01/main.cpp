/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:20:07 by upolat            #+#    #+#             */
/*   Updated: 2025/04/07 10:28:26 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "iostream"
#include <cassert>

#define GREEN "\033[32m"
#define DEFAULT "\033[39m"

int main(void) {
	Data* test = new Data;

	test->str = "Hive";
	test->value = 42;
	test->flag = true;

	std::cout << GREEN << "Before serialization:" << DEFAULT << std::endl;
	std::cout << test->str << std::endl;
	std::cout << test->value << std::endl;
	std::cout << test->flag << std::endl;

	
	uintptr_t raw = Serializer::serialize(test);
	Data *test2 = Serializer::deserialize(raw);

    std::cout << GREEN << "After deserialization:" << DEFAULT << std::endl;
	std::cout << test2->str << std::endl;
	std::cout << test2->value << std::endl;
	std::cout << test2->flag << std::endl;

	assert(test == test2);
	std::cout << GREEN << "Assertion passed: test == test2" << DEFAULT << std::endl;

	delete test;
}