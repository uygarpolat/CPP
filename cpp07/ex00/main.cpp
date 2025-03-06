/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:06:52 by upolat            #+#    #+#             */
/*   Updated: 2025/03/06 10:17:45 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "iostream"

int main(void) {
	std::cout << max<int>(3,5) << std::endl;
	std::cout << max<double>(42.4242, 42.5252) << std::endl;
	std::cout << min<char>('a', 'b') << std::endl;
	std::cout << min<int>('a', 'b') << std::endl;

	int first = -100;
	int second = 100;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	swap<int>(first, second);
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	return 0;
}