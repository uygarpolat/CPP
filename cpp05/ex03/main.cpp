/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:57:51 by upolat            #+#    #+#             */
/*   Updated: 2024/11/29 00:20:21 by upolat           ###   ########.fr       */
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
    try {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("shrubbery creation", "Zoidberg");
        std::cout << *rrf << std::endl;
        delete rrf;
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }

    std::cout << " *****   TEST 2   ***** " << std::endl;
    // Trying to create an invalid form
    try {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("vice presidential pardon", "Leila");
        std::cout << *rrf << std::endl;
        delete rrf;
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }

    std::cout << " *****   TEST 3   ***** " << std::endl;
    // Creating a valid form and then executing it
    try {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        Bureaucrat hermes(5, "Hermes");
        Bureaucrat fry(70, "Fry");

        fry.signForm(*rrf); // Fry will sign the form
        fry.executeForm(*rrf); // Fry won't be able to execute the form (Grade too low)
        hermes.signForm(*rrf); // Hermes won't be able to sign the form (alredy signed)
        hermes.executeForm(*rrf); // Hermes will execute the form

        delete rrf;
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }
    return 0;
}