/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:24:07 by upolat            #+#    #+#             */
/*   Updated: 2025/04/09 22:00:26 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <limits>
#include <exception>
#include "easyfind.hpp"

int main(void) {
    // Test 1: Standard vector with the value present
    try {
        std::vector<int> vec = {1, 2, 3, 4, 5};
        std::cout << "Test 1 - Vector (present): " << easyfind(vec, 3) << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 2: Standard vector with the value absent
    try {
        std::vector<int> vec = {1, 2, 3, 4, 5};
        std::cout << "Test 2 - Vector (absent): " << easyfind(vec, 42) << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 3: Empty container
    try {
        std::vector<int> vec;
        std::cout << "Test 3 - Empty vector: " << easyfind(vec, 1) << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 4: Single element container with a match
    try {
        std::vector<int> vec = {42};
        std::cout << "Test 4 - Single element (match): " << easyfind(vec, 42) << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 5: Single element container without a match
    try {
        std::vector<int> vec = {42};
        std::cout << "Test 5 - Single element (non-match): " << easyfind(vec, 5) << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 6: Container with multiple occurrences; should return the first occurrence.
    try {
        std::vector<int> vec = {1, 3, 3, 3, 5};
        std::cout << "Test 6 - Duplicates test: " << easyfind(vec, 3) << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 7: Testing INT_MAX
    try {
        std::vector<int> vec = {std::numeric_limits<int>::min(), 0, std::numeric_limits<int>::max()};
        std::cout << "Test 7 - Extreme values test: " << easyfind(vec, std::numeric_limits<int>::max()) << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test 8: Using a different container type (std::list)
    try {
        std::list<int> lst = {10, 20, 30, 40, 50};
        std::cout << "Test 8 - List test (present): " << easyfind(lst, 40) << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

	// Test 9: Using a different container type (std::array)
	try {
		std::array<int, 5> arr = {10, 20, -30, 40, 50};
		std::cout << "Test 9 - Array test (present): " << easyfind(arr, -30) << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
    
    return 0;
}
