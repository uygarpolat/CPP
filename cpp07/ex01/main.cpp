/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:07:17 by upolat            #+#    #+#             */
/*   Updated: 2025/04/08 11:44:21 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <class T> void print(T const &x)
{
	std::cout << x << std::endl;
}

int main(void) {

	int			arr1[5] = {1, 2, 3, 4, 5};
	std::string arr2[5] = {"c", "plus", "plus", "is", "interesting"};
	char		arr3[6] = {'H', 'i', 'v', 'e', 'r', '!'};

	size_t len = 5;
	iter(arr1, len, print);
	iter(arr2, len, print);
	++len;
	iter(arr3, len, print);
	
	return 0;
}
