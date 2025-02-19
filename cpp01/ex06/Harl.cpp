/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 02:43:06 by upolat            #+#    #+#             */
/*   Updated: 2025/02/19 14:09:33 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

void Harl::_debug( void ) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" <<std::endl;
    std::cout << std::endl;
}
void Harl::_info( void ) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" <<std::endl;
    std::cout << std::endl;
}
void Harl::_warning( void ) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." <<std::endl;
    std::cout << std::endl;
}
void Harl::_error( void ) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." <<std::endl;
    std::cout << std::endl;
}

int intify(std::string &level) {
    if (level == "DEBUG") { return DEBUG;}
    if (level == "INFO") { return INFO;}
    if (level == "WARNING") { return WARNING;}
    if (level == "ERROR") { return ERROR;}
    return UNKNOWN;
}

void	Harl::complain(std::string level)
{
    int level_int = intify(level);
	switch(level_int) {
        case DEBUG:
            _debug();
            [[fallthrough]];
        case INFO:
            _info();
            [[fallthrough]];
        case WARNING:
            _warning();
            [[fallthrough]];
        case ERROR:
            _error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}