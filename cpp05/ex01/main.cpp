/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:57:51 by upolat            #+#    #+#             */
/*   Updated: 2025/03/27 12:23:35 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {

    std::cout << "***** TEST 1 *****" << std::endl;
    // Trying to create a lomake with too high execution grade
    try {
        Form form1("Unlawful", 0, 42);
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }

    /* --------------------------- */

    std::cout << "***** TEST 2 *****" << std::endl;
    // Trying to create a lomake with too high sign grade
    try {
        Form form2("Unlawful again", 42, 0);
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }

    /* --------------------------- */

        std::cout << "***** TEST 3 *****" << std::endl;
    // Trying to create a lomake with too low execution grade
    try {
        Form form3("Unlawful again", 151, 42);
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }

    /* --------------------------- */

        std::cout << "***** TEST 4 *****" << std::endl;
    // Trying to create a lomake with too low sign grade
    try {
        Form form4("Unlawful again", 42, 151);
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }

    /* --------------------------- */
    
    std::cout << "***** TEST 5 *****" << std::endl;
    // Testing << overload operator
	try {
		Form form5("1099", 100, 50);
		std::cout << form5 << std::endl;
	}
	catch (std::exception &e) {
        std::cout << e.what();
    }
	

    /* --------------------------- */
    
    std::cout << "***** TEST 6 *****" << std::endl;
    // Performing regular form signing operations. No exceptions expected in the main function.
    try {
		Form form6("Lomake", 1, 40);
		std::cout << form6 << std::endl;
		Bureaucrat bur39(39, "Bureaucrat-39");
		Bureaucrat bur41(41, "Bureaucrat-41");
		std::cout << bur39 << std::endl;
		std::cout << bur41 << std::endl;
		bur41.signForm(form6);
		bur39.signForm(form6);
		bur39.signForm(form6);
		std::cout << form6 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}

    /* --------------------------- */

    std::cout << "***** TEST 7 *****" << std::endl;
    // Testing copy constructor
	try {
		Form form7("this isn't even my final FORM", 42, 24);
		Form form8(form7);
		std::cout << form7 << std::endl;
		std::cout << form8 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}

    /* --------------------------- */

    std::cout << "***** TEST 8 *****" << std::endl;
    // Testing copy assign operator. Only signature status is copied, because rest is const.
    try {
		Form form9("THIS is my final FORM", 1, 1);
		Form form10;
		form10 = form9;
		std::cout << form9 << std::endl;
		std::cout << form10 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}

    return 0;
}