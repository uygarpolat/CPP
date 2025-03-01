/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:32:06 by upolat            #+#    #+#             */
/*   Updated: 2025/03/01 20:56:26 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Unknown Form"), _signed(false), _executeGrade(150), _signGrade(150) {}

Form::Form(const std::string &name, int executeGrade, int signGrade)
    : _name(name), _signed(false), _executeGrade(executeGrade), _signGrade(signGrade) {
                if (_signGrade < 1 || _executeGrade < 1)
            throw GradeTooHighException();
        else if (_signGrade > 150 || _executeGrade > 150)
            throw GradeTooLowException();
}


Form::Form(const Form &other)
     : _name(other._name), _signed(other._signed), _executeGrade(other._executeGrade), _signGrade(other._signGrade) {}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

Form::~Form() {}

std::string const &Form::getName(void) const {
    return _name;
}
bool Form::getSign(void) const {
    return _signed;
}
int Form::getSignGrade(void) const {
    return _signGrade;
}
int Form::getExecuteGrade(void) const {
    return _executeGrade;
}

const char *Form::GradeTooHighException::what() const noexcept {
    return "Grade too high!\n";
}
const char *Form::GradeTooLowException::what() const noexcept {
    return "Grade too low!\n";
}
const char *Form::FormAlreadySignedException::what() const noexcept {
    return "Form already signed!\n";
}

void Form::beSigned(Bureaucrat &bureaucrat) {
    if (getSign())
		throw FormAlreadySignedException();
    if (getSignGrade() < bureaucrat.getGrade())
            throw GradeTooLowException();
    _signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
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