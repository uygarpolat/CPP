/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:25:54 by upolat            #+#    #+#             */
/*   Updated: 2025/04/07 21:01:06 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <assert.h>

int main(void)
{
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
	return 0;
}
