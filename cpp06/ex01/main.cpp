/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:20:07 by upolat            #+#    #+#             */
/*   Updated: 2025/03/06 09:39:55 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "iostream"

int main(void) {
	Data* test = new Data;

	test->str = "Hive";
	test->value = 42;
	test->flag = true;

	std::cout << test->str << std::endl;
	std::cout << test->value << std::endl;
	std::cout << test->flag << std::endl;

	uintptr_t raw = Serializer::serialize(test);
	Data *test2 = Serializer::deserialize(raw);

	std::cout << test2->str << std::endl;
	std::cout << test2->value << std::endl;
	std::cout << test2->flag << std::endl;

	delete test;
}