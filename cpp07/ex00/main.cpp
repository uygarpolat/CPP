/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:06:52 by upolat            #+#    #+#             */
/*   Updated: 2025/04/07 21:11:47 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>
#include <assert.h>

int main(void) {
	std::cout << max(3,5) << std::endl;
	assert(max(3,5) == 5);
	std::cout << max(42.4242, 42.5252) << std::endl;
	assert(max(42.4242, 42.5252) == 42.5252);
	std::cout << min('a', 'b') << std::endl;
	assert(min('a', 'b') == 'a');
	std::cout << min<int>('a', 'b') << std::endl;
	assert(min<int>('a', 'b') == 'a');
	std::cout << min<double>(1,  3.1) << std::endl;
	assert(min<double>(1,  3.1) == 1);

	int first = -100;
	int second = 100;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	swap(first, second);
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	assert(first == 100);
	assert(second == -100);

	std::cout << std::endl << "Tests from the subject:" << std::endl << std::endl;

	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}