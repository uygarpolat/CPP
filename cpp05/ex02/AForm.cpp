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

AForm::AForm() : _name("Unknown Form"), _signed(false), _executeGrade(150), _signGrade(150) {}

AForm::AForm(const std::string &name, int executeGrade, int signGrade)
    : _name(name), _signed(false), _executeGrade(executeGrade), _signGrade(signGrade) {
                if (_signGrade < 1 || _executeGrade < 1)
            throw GradeTooHighException();
        else if (_signGrade > 150 || _executeGrade > 150)
            throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
     : _name(other._name), _signed(other._signed), _executeGrade(other._executeGrade), _signGrade(other._signGrade) {}

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

void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (getSign())
		throw FormAlreadySignedException();
    if (getSignGrade() < bureaucrat.getGrade())
            throw GradeTooLowException();
    _signed = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << "Form "
        << form.getName()
        << " has an execution grade of "
        << form.getExecuteGrade()
        << " and sign grade of "
        << form.getSignGrade()
        << ", and it is currently";
    if (!form.getSign())
        out << " NOT";
    out << " signed."; 

    return out;
}