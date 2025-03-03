/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:35:20 by upolat            #+#    #+#             */
/*   Updated: 2025/03/03 08:51:30 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    
    if (argc != 2)
        return 1;
    
    ScalarConverter a;
	//std::string arg = argv[1];

	a.convert(static_cast<std::string>(argv[1]));

    return 0;
}