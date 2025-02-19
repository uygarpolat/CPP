/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:29:43 by upolat            #+#    #+#             */
/*   Updated: 2025/02/19 20:49:27 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main() {

	std::cout << "\033[31m" << "Red " << "\033[0m" << "indicates failed test, " << "\033[32m" << "green" << "\033[0m" << " indicates passed test." << std::endl;

	std::cout << "\033[32m";
	
    // Test 1: Point inside the triangle
    Point const a1(0, 0);
    Point const b1(4, 0);
    Point const c1(2, 4);
    Point const point1(2, 2);

    if (bsp(a1, b1, c1, point1))
        std::cout << "Test 1: The point is inside the triangle!" << std::endl;
    else
        std::cout
		<< "\033[31m" << "Test 1: The point is NOT inside the triangle!"
		<< "\033[32m" << std::endl;

    // Test 2: Point outside the triangle
    Point const a2(0, 0);
    Point const b2(4, 0);
    Point const c2(2, 4);
    Point const point2(5, 5);

    if (bsp(a2, b2, c2, point2))
		std::cout
		<< "\033[31m" << "Test 2: The point is inside the triangle!"
		<< "\033[32m" << std::endl;
    else
        std::cout << "Test 2: The point is NOT inside the triangle!" << std::endl;

    // Test 3: Point on the edge of the triangle
    Point const a3(0, 0);
    Point const b3(4, 0);
    Point const c3(2, 4);
    Point const point3(2, 0);

    if (bsp(a3, b3, c3, point3))
		std::cout
		<< "\033[31m" << "Test 3: The point is inside the triangle!"
		<< "\033[32m" << std::endl;
    else
        std::cout << "Test 3: The point is NOT inside the triangle!" << std::endl;

    // Test 4: Point is one of the triangle's vertices
    Point const a4(0, 0);
    Point const b4(4, 0);
    Point const c4(2, 4);
    Point const point4(0, 0);

    if (bsp(a4, b4, c4, point4))
		std::cout
		<< "\033[31m" << "Test 4: The point is inside the triangle!"
		<< "\033[32m" << std::endl;
    else
        std::cout << "Test 4: The point is NOT inside the triangle!" << std::endl;

    // Test 5: All 4 points are on a line.
    Point const a5(0, 0);
    Point const b5(2, 2);
    Point const c5(4, 4);
    Point const point5(3, 3);

    if (bsp(a5, b5, c5, point5))
		std::cout
		<< "\033[31m" << "Test 5: The point is inside the triangle!"
		<< "\033[32m" << std::endl;
	else
        std::cout << "Test 5: The point is NOT inside the triangle!" << std::endl;

    // Test 6: Point far outside the triangle
    Point const a6(0, 0);
    Point const b6(4, 0);
    Point const c6(2, 4);
    Point const point6(-10, -10);

    if (bsp(a6, b6, c6, point6))
		std::cout
		<< "\033[31m" << "Test 2: The point is inside the triangle!"
		<< "\033[32m" << std::endl;
    else
        std::cout << "Test 6: The point is NOT inside the triangle!" << std::endl;

	std::cout << "\033[0m";
    return 0;
}