/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:35:20 by upolat            #+#    #+#             */
/*   Updated: 2024/11/29 15:58:46 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

int main(int argc, char **argv) {
    
    if (argc != 2)
        return 1;
    std::string arg = argv[1];
    if (arg.length() == 1) {
        if (isdigit(arg[0]))
            return 1; // 1 is for int
        else
            return 2; // 2 is for char
    }
    else
    
    int total = 0;
	std::string arg = argv[1];
	for (char& c : arg)
        if (isdigit(c))
            total++;
    
    //int test = std::stoi(argv[1]);
    std::cout << total << std::endl;
}