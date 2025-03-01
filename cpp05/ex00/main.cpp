/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:57:51 by upolat            #+#    #+#             */
/*   Updated: 2025/03/01 19:20:26 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {

    // Creating a bureaucrat and incrementing and decrementing its value. No exceptions should be thrown.
    std::cout << "***** TEST 1 *****" << std::endl;
    try {
        Bureaucrat b1;
        Bureaucrat b2(99, "Hannibal Lecter");
        std::cout << b2 << std::endl;
        std::cout << "Name retrieved manually: " << b2.getName() << std::endl;
        std::cout << "Grade retrieved manually: " << b2.getGrade() << std::endl;
        b2.incrementGrade(); // Grade increased to 98
        b2.incrementGrade(); // Grade increased to 97
        b2.incrementGrade(); // Grade increased to 96
        b2.incrementGrade(); // Grade increased to 95
        b2.incrementGrade(); // Grade increased to 94
        b2.incrementGrade(); // Grade increased to 93
        b2.decrementGrade(); // Grade decreased to 94
        std::cout << b2 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }

    // Creating a bureaucrat with too low grade, should throw "Grade too low" exception
    std::cout << "***** TEST 2 *****" << std::endl;
    try {
        Bureaucrat b3(151, "Lowly McLowdy");
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }
    
    // Creating a bureaucrat with too high grade, should throw "Grade too high" exception
    std::cout << "***** TEST 3*****" << std::endl;
    try {
        Bureaucrat b4(0, "Higher Highson");
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }
    
    // Creating a bureaucrat and incrementing it too much to get a "Grade too high" exception
    std::cout << "***** TEST 4 *****" << std::endl;
    try {
        Bureaucrat b5(11, "Testy Tesserract");
        std::cout << b5 << std::endl;
        for (int i = 0; i < 10; i++)
            b5.incrementGrade();
        std::cout << b5 << std::endl;
        b5.incrementGrade(); // Should throw "Grade too high exception"
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }
    
    // Creating a bureaucrat and decrementing it too much to get a "Grade too low" exception
    std::cout << "***** TEST 6 *****"  << std::endl;
    try {
        Bureaucrat b6(108, "Testy Tesserract");
        std::cout << b6 << std::endl;
        for (int i = 0; i < 42; i++)
            b6.decrementGrade();
        std::cout << b6 << std::endl;
        b6.decrementGrade(); // Should throw "Grade too low" exception
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }
    
    // Testing copy constructor, the two prints should be identical.
    std::cout << "***** TEST 7 *****"  << std::endl;
    try {
            Bureaucrat b7(14, "Copier Machine");
            Bureaucrat b8(b7);
            std::cout << b7 << std::endl;
            std::cout << b8 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }
    
    // Copy assignment operator overload test
    std::cout << "***** TEST 8 *****"  << std::endl;
    try {
        Bureaucrat *b9 = new Bureaucrat(14, "Copier Machine");
        Bureaucrat *b10 = new Bureaucrat();
        std::cout << *b9 << std::endl;
        std::cout << *b10 << std::endl;
        *b10 = *b9;
        // The following will change the grade of *b10 to 14 but not its name, because name is const.
        std::cout << *b10 << std::endl;
        delete b9;
        delete b10;
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }

    // Creating a bureaucrat with negative grade, should throw "Grade too high" exception
    std::cout << "***** TEST 9 *****" << std::endl;
    try {
        Bureaucrat b11(-1, "Negatory Nelly");
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }
    return 0;
}