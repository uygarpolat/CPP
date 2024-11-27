/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:56:51 by upolat            #+#    #+#             */
/*   Updated: 2024/11/27 22:43:28 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>

class Form;

class Bureaucrat {
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        Bureaucrat(int grade, const std::string &name);
        
        void decrementGrade(void);
        void incrementGrade(void);

        class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

        int getGrade(void) const;
        std::string const &getName(void) const;
        void signForm(Form &form);

    private:
        std::string const _name;
        int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);