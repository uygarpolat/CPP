/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:35:20 by upolat            #+#    #+#             */
/*   Updated: 2025/03/05 20:06:44 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    
    if (argc != 2) {
		std::cerr << "Usage: ./convert [value]" << std::endl;
        return 1;
	}
	
    try {
        ScalarConverter::convert(argv[1]);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
		return 1;
    }

    return 0;
}