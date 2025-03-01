/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:32:15 by upolat            #+#    #+#             */
/*   Updated: 2025/03/01 23:49:57 by upolat           ###   ########.fr       */
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
        virtual ~AForm();
        AForm(const std::string &name, int signGrade, int executeGrade);
        
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
        class SignatureIncompleteException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

        std::string const &getName(void) const;
        bool getSign() const;
        void setSign(bool boolSign);
        int getSignGrade(void) const;
        int getExecuteGrade(void) const;
        void beSigned(Bureaucrat &bureaucrat);
        virtual const std::string getTarget() const = 0;
        virtual void execute(Bureaucrat const & executor) const = 0;

    private:
        const std::string   _name;
        bool                _signed;
        const int           _signGrade;
        const int           _executeGrade;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);