/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:57:51 by upolat            #+#    #+#             */
/*   Updated: 2025/03/02 01:08:34 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {

    std::cout << " *****   TEST 1   ***** " << std::endl;
    // Trying to create a valid form
	AForm* rrf = nullptr;
	try {
		Intern someRandomIntern;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Zoidberg");
		std::cout << *rrf << std::endl;
		delete rrf;
		rrf = nullptr;
	}
	catch (std::exception &e) {
		delete rrf;
		std::cout << e.what();
	}
	

    std::cout << " *****   TEST 2   ***** " << std::endl;
    // Trying to create an invalid form
	AForm* rrf2 = nullptr;
    try {
        Intern someRandomIntern;
        rrf2 = someRandomIntern.makeForm("vice presidential pardon", "Leila");
        std::cout << *rrf2 << std::endl;
        delete rrf2;
    }
    catch (std::exception &e) {
		delete rrf2;
        std::cout << e.what();
    }

    std::cout << " *****   TEST 3   ***** " << std::endl;
    // Creating a valid form and then executing it
	AForm* rrf3 = nullptr;
    try {
        Intern someRandomIntern;
        rrf3 = someRandomIntern.makeForm("robotomy request", "Bender");

        Bureaucrat hermes(5, "Hermes");
        Bureaucrat fry(70, "Fry");

        fry.signForm(*rrf3); // Fry will sign the form
        fry.executeForm(*rrf3); // Fry won't be able to execute the form (Grade too low)
        hermes.signForm(*rrf3); // Hermes won't be able to sign the form (alredy signed)
        hermes.executeForm(*rrf3); // Hermes will execute the form

        delete rrf3;
    }
    catch (std::exception &e) {
		delete rrf3;
        std::cout << e.what();
    }
    return 0;
}