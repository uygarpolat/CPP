/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:28:26 by upolat            #+#    #+#             */
/*   Updated: 2024/11/28 21:18:52 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include <random>

RobotomyRequestForm::RobotomyRequestForm() : AForm(), _target("Unknown") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}
    
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade()) {
    setSign(other.getSign());
    _target = other._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
        setSign(other.getSign());
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string RobotomyRequestForm::getTarget(void) const {
    return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!getSign())
		throw AForm::SignatureIncompleteException();
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();
	
    std::cout << " * Makes some drilling noises * " << std::endl;
    if (std::random_device{}() % 2)
        std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomy failed!" << std::endl;
}