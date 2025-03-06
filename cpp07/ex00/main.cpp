/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:06:52 by upolat            #+#    #+#             */
/*   Updated: 2025/03/06 10:25:22 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "iostream"

int main(void) {
	std::cout << max(3,5) << std::endl;
	std::cout << max(42.4242, 42.5252) << std::endl;
	std::cout << min('a', 'b') << std::endl;
	std::cout << min<int>('a', 'b') << std::endl;

	int first = -100;
	int second = 100;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	swap(first, second);
	std::cout << first << std::endl;
	std::cout << second << std::endl;

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