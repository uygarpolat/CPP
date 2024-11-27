/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:56:17 by upolat            #+#    #+#             */
/*   Updated: 2024/11/28 01:01:54 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
    : _name("Unnamed bureaucrat"), _grade(150) {
    std::cout << "Unnamed bureaucrat created with lowest grade: 150." << std::endl;
}

Bureaucrat::Bureaucrat(int grade, const std::string &name)
    : _name(name), _grade(grade) {
        if (grade < 1)
            throw GradeTooHighException();
        else if (grade > 150)
            throw GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!\n";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

int Bureaucrat::getGrade(void) const {
    return _grade;
}

std::string const &Bureaucrat::getName(void) const {
    return _name;
}

void Bureaucrat::incrementGrade(void) {
    if (_grade <= 1)
        throw GradeTooHighException();
    else if (_grade >= 151)
        throw GradeTooLowException();
    this->_grade--;
}

void Bureaucrat::decrementGrade(void) {  
    if (_grade <= 0)
        throw GradeTooHighException();
    else if (_grade >= 150)
        throw GradeTooLowException();
    this->_grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        if (form.getSign())
          std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << this->getName()
        << " couldn't sign "
        << form.getName() 
        << " because "
        << e.what();
    }
}