/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:56:51 by upolat            #+#    #+#             */
/*   Updated: 2024/11/27 10:34:36 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat {
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        Bureaucrat(unsigned int grade, const std::string &name);
        Bureaucrat &operator << (const Bureaucrat &other);

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

        unsigned int getGrade(void) const;
        std::string const &getName(void) const;

    private:
        std::string const _name;
        unsigned int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);