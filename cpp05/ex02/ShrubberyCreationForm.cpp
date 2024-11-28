/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:36:01 by upolat            #+#    #+#             */
/*   Updated: 2024/11/28 16:50:05 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("Unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}
    

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade()) {
    setSign(other.getSign());
    _target = other._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        setSign(other.getSign());
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::beSigned(Bureaucrat &bureaucrat) {
    if (getSign())
		throw FormAlreadySignedException();
    if (getSignGrade() < bureaucrat.getGrade())
            throw GradeTooLowException();
    setSign(true);
}

const std::string ShrubberyCreationForm::getTarget(void) const {
    return _target;
}