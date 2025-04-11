/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:59:01 by upolat            #+#    #+#             */
/*   Updated: 2025/04/12 02:57:47 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char** argv) {
	try {
		if (argc != 2)
			throw std::runtime_error("Error");
		RPN rpn(argv[1]);
		std::cout << rpn.parseRpn() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}