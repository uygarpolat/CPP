/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:17:31 by upolat            #+#    #+#             */
/*   Updated: 2024/11/29 00:19:07 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern &Intern::operator=(const Intern &other) {
    if (this != &other) {
        (void)other;
    }
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string formName, std::string formTarget) {
    std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
    AForm *shrub = new ShrubberyCreationForm(formTarget);
    AForm *robo = new RobotomyRequestForm(formTarget);
    AForm *pres = new PresidentialPardonForm(formTarget);
    
    AForm *forms[] = {shrub, robo, pres};

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            delete forms[(i + 1) % 3];
            delete forms[(i + 2) % 3];
            std::cout << "Intern creates " << formNames[i] << std::endl;
            return forms[i];
        }
    }
    for (int i = 0; i < 3; i++)
        delete forms[i];
    throw std::invalid_argument(formName + " is not a valid form...\n");
}