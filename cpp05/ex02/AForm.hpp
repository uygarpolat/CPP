/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:32:15 by upolat            #+#    #+#             */
/*   Updated: 2024/11/28 12:20:07 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {
    public:
        AForm();
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        ~AForm();
        AForm(const std::string &name, int executeGrade, int signGrade);
        
        class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
        class FormAlreadySignedException : public std::exception {
			public:
				const char* what() const throw();
		};

        std::string const &getName(void) const;
        bool getSign(void) const;
        int getSignGrade(void) const;
        int getExecuteGrade(void) const;
        void beSigned(Bureaucrat &bureaucrat);
    private:
        const std::string   _name;
        bool                _signed;
        const int           _executeGrade;
        const int           _signGrade;
        
};

std::ostream &operator<<(std::ostream &out, const AForm &form);