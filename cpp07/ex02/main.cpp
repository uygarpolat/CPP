/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:25:54 by upolat            #+#    #+#             */
/*   Updated: 2025/04/08 10:27:02 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <assert.h>

#define GREEN "\033[32m"
#define DEFAULT "\033[39m"

int main(void)
{
	std::cout << GREEN << "1. Testing the Array class with integers" << DEFAULT << std::endl;
	Array<int> arr(5);
	try {
		for (unsigned int i = 0; i < arr.size(); ++i)
			arr[i] = i * 2;
		for (unsigned int i = 0; i < arr.size(); ++i)
			std::cout << arr[i] << " ";
		std::cout << std::endl;

	
		std::cout << arr[5] << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << GREEN << "2. Testing the copy constructor" << DEFAULT << std::endl;
	try  {
		Array<int> arr2(arr);
		for (unsigned int i = 0; i < arr2.size(); ++i)
			std::cout << arr2[i] << " ";
		std::cout << std::endl;

		assert(arr2.size() == arr.size());

		std::cout << arr[-1] << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << GREEN << "3. Testing the assignment operator" << DEFAULT << std::endl;
	try {
		Array<int> arr3 = arr;
		for (unsigned int i = 0; i < arr3.size(); ++i)
			std::cout << arr3[i] << " ";
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << GREEN << "4. Testing it with a different type (std::string)" << DEFAULT << std::endl;

	try {
		Array<std::string> strArr(3);
		strArr[0] = "Hello";
		strArr[1] = "World";
		strArr[2] = "!";
		for (unsigned int i = 0; i < strArr.size(); ++i)
			std::cout << strArr[i] << " ";
		std::cout << std::endl;

		Array<std::string> strArr2(strArr);
		for (unsigned int i = 0; i < strArr2.size(); ++i)
			std::cout << strArr2[i] << " ";
		std::cout << std::endl;

		// Testing the assignment operator's deep copy
		assert(&strArr2 != &strArr);

		// We are changing the value of strArr2[0] to see if it affects strArr[0]
		assert(strArr2[0] == strArr[0]);
		strArr2[0] = "Goodbye";
		assert(strArr2[0] != strArr[0]);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
