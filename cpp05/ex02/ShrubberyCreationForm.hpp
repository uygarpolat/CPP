/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:36:04 by upolat            #+#    #+#             */
/*   Updated: 2025/03/01 23:29:00 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);

        const std::string getTarget() const override;
        void execute(Bureaucrat const & executor) const override;

        class OpenFileException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

    private:
        std::string   _target;
};