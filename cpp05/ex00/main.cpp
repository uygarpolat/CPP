/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:57:51 by upolat            #+#    #+#             */
/*   Updated: 2024/11/27 09:57:57 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {
    try {
        Bureaucrat b1;
        Bureaucrat b2(99, "Hannibal Lecter");
        std::cout << b2 << std::endl;
        std::cout << b2.getName() << std::endl;
        std::cout << b2.getGrade() << std::endl;
        b2.incrementGrade();
        b2.incrementGrade();
        std::cout << b2 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }

    std::cout << "saad" " sdasd" << std::endl;
    return 0;
}