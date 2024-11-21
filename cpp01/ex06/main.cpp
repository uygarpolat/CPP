/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 02:43:12 by upolat            #+#    #+#             */
/*   Updated: 2024/11/21 13:15:10 by upolat           ###   ########.fr       */
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