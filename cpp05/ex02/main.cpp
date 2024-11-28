/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:57:51 by upolat            #+#    #+#             */
/*   Updated: 2024/11/28 20:18:57 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {

    try {
        // Testing creating a ShrubberyCreationForm object
        AForm *shrub = new ShrubberyCreationForm("home");
        std::cout << *shrub << std::endl;

        // Testing the copy constructor (via polymorphism, which requires casting)
        AForm *shrub2 = new ShrubberyCreationForm(*static_cast<ShrubberyCreationForm*>(shrub));
        std::cout << *shrub2 << std::endl;

        delete shrub;
        delete shrub2;

        // Testing assignment operator, but assignment operator doesn't support
        // polymorphism in C++, so we switch to concrete instances.
        ShrubberyCreationForm shrub3("garden");
        ShrubberyCreationForm shrub4("work");

        // Instertion overload is not required for concrete classes in this project,
        // so we call getters for target.
        std::cout << "Target is: " << shrub3.getTarget() << " (supposed to be garden)" << std::endl;
        std::cout << "Target is: " << shrub4.getTarget() << " (supposed to be work)" << std::endl;

        shrub4 = shrub3;

        std::cout << "Target is: " << shrub3.getTarget() << " (supposed to be garden)" << std::endl;
        std::cout << "Target is: " << shrub4.getTarget() << " (supposed to be garden)" << std::endl;

    }
    catch (std::exception &e) {
        std::cout << e.what();
    }

    AForm *shrub5 = new ShrubberyCreationForm("cabin");
    Bureaucrat buro(40, "Gale");
    buro.signForm(*shrub5);
    buro.executeForm(*shrub5);

    delete shrub5;

    AForm *robo = new RobotomyRequestForm("robotomized");
    Bureaucrat buro2(40, "Gale");
    buro2.signForm(*robo);
    buro2.executeForm(*robo);

    delete robo;

    AForm *bandit = new PresidentialPardonForm("bandit");
    Bureaucrat buro3(3, "Marvin");
    buro3.signForm(*bandit);
    buro3.executeForm(*bandit);

    delete bandit;
    
    return 0;
}