/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:36:01 by upolat            #+#    #+#             */
/*   Updated: 2025/03/01 23:29:14 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

#define tree "\n\
             &&& &&  & &&\n\
          && &\\/&\\|& ()|/ @, &&\n\
          &\\/(/&/&||/& /_/)_&/_&\n\
       &() &\\/&|()|\\/&\\/ '%' & ()\n\
      &_\\_&&_\\ |& |&&/&__%_/_& &&\n\
     &&   && & &| &| /& & % ()& /&&\n\
      ()&_---()&\\&\\|&&-&&--%---()~\n\
          &&     \\|||\n\
                 |||\n\
                 |||\n\
                 |||\n\
           , -=-~  .-^- _\n\
  _____________________________\n"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("Unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade()) {
    setSign(other.getSign());
    _target = other._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        setSign(other.getSign());
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string ShrubberyCreationForm::getTarget(void) const {
    return _target;
}

const char *ShrubberyCreationForm::OpenFileException::what() const noexcept {
    return "Cannot open outfile!\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!getSign())
		throw AForm::SignatureIncompleteException();
	if (executor.getGrade() > getExecuteGrade())
		throw AForm::GradeTooLowException();
	
	std::ofstream out((_target + "_shrubbery").c_str());
	if (!out.is_open())
		throw ShrubberyCreationForm::OpenFileException();
	out << tree;
	out.close();
}