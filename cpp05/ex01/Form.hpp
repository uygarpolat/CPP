/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:32:15 by upolat            #+#    #+#             */
/*   Updated: 2025/03/01 20:54:32 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form {
    public:
        Form();
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();
        Form(const std::string &name, int executeGrade, int signGrade);
        
        class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
        class FormAlreadySignedException : public std::exception {
			public:
				const char* what() const noexcept override;
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

std::ostream &operator<<(std::ostream &out, const Form &form);