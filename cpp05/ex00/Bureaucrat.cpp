/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:56:17 by upolat            #+#    #+#             */
/*   Updated: 2024/11/27 10:34:07 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(unsigned int grade) {
    try {
        if (grade < 1)
            throw GradeTooHighException();
        else if (grade > 150)
            throw GradeTooLowException();
        _grade = grade;
    }
    catch (const std::exception & e) {
        
    }
}

/*
Bureaucrat::Bureaucrat(const Bureaucrat &other) : data(other.data) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}
*/

Bureaucrat::~Bureaucrat() {}

unsigned int Bureaucrat::getGrade(void) const {
    return _grade;
}

std::string &Bureaucrat::getName(void) const {
    return _name;
}

Bureaucrat &Bureaucrat::operator++() {
    
    try {
        if (this->_grade > 0 && this->_grade < 150)
            this->_grade++;
        else
            throw (...);
    }
    catch (this->_grade)
        std::cout << "Grade cannot be incremented..." << std::endl;
    
    return *this;
}

Bureaucrat &Bureaucrat::operator--() {
    
    this->_grade -= 1;
    return *this;
}