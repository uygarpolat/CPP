/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:32:06 by upolat            #+#    #+#             */
/*   Updated: 2024/11/28 12:19:47 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Unknown Form"), _signed(false), _signGrade(150), _executeGrade(150) {}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
    : _name(name), _signGrade(signGrade), _executeGrade(executeGrade) {
        _signed = false;
        if (_signGrade < 1 || _executeGrade < 1)
            throw GradeTooHighException();
        else if (_signGrade > 150 || _executeGrade > 150)
            throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
     : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

AForm::~AForm() {}

std::string const &AForm::getName(void) const {
    return _name;
}
bool AForm::getSign(void) const {
    return _signed;
}
int AForm::getSignGrade(void) const {
    return _signGrade;
}
int AForm::getExecuteGrade(void) const {
    return _executeGrade;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade too high!\n";
}
const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade too low!\n";
}
const char *AForm::FormAlreadySignedException::what() const throw() {
    return "Form already signed!\n";
}
const char *AForm::SignatureIncompleteException::what() const throw() {
    return "Form net yet signed!\n";
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (getSign())
		throw FormAlreadySignedException();
    if (getSignGrade() < bureaucrat.getGrade())
            throw GradeTooLowException();
    _signed = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << form.getName()
        << " has a sign grade of "
        << form.getSignGrade()
        << ", execution grade of "
        << form.getExecuteGrade()
        << ", its target is "
        << form.getTarget()
        << ", and it is currently";
    if (!form.getSign())
        out << " NOT";
    out << " signed."; 

    return out;
}

void AForm::setSign(bool boolSign) {
    _signed = boolSign;
}