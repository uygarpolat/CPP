/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 02:43:12 by upolat            #+#    #+#             */
/*   Updated: 2025/02/19 13:58:14 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main (int argc, char **argv) {
    Harl harl;

    if (argc != 2) {
        std::cout << "Usage: ./harlFilter <log_level: DEBUG, INFO, WARNING, ERROR>" << std::endl;
        return 0;
    }
    harl.complain(argv[1]);
    return 0;
}