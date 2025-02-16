/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyAwesomePhonebook.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:04:31 by upolat            #+#    #+#             */
/*   Updated: 2025/02/16 16:54:18 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyAwesomePhonebook.hpp"

PhoneBook::PhoneBook() : counter(0)
{
	std::cout << "PhoneBook created." << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destroyed." << std::endl;
}

void Contact::setFirstName(const std::string& FirstName)
{
		_FirstName = FirstName;
}
std::string Contact::getFirstName() const
{
	return (_FirstName);
}

void Contact::setLastName(const std::string& LastName)
{
		_LastName = LastName;
}
std::string Contact::getLastName() const
{
	return (_LastName);
}

void Contact::setNickname(const std::string& Nickname)
{
	_Nickname = Nickname;
}
std::string Contact::getNickname() const
{
	return (_Nickname);
}

void Contact::setPhoneNumber(const std::string& PhoneNumber)
{
	_PhoneNumber = PhoneNumber;
}
std::string Contact::getPhoneNumber() const
{
	return (_PhoneNumber);
}

void Contact::setDarkestSecret(const std::string& DarkestSecret)
{
	_DarkestSecret = DarkestSecret;
}
std::string Contact::getDarkestSecret() const
{
	return (_DarkestSecret);
}

std::string formatColumn(const std::string& text, int width)
{
    if (text.length() > static_cast<std::string::size_type>(width))
        return (text.substr(0, width - 1) + ".");
	else
	{
		// Return right-aligned text within the specified width
		std::ostringstream oss;
		oss << std::setw(width) << std::right << text;
		return (oss.str());
    }
}

void	ft_cout(std::string input, int i)
{
	std::cout << input;
	while (i--)
		std::cout << std::endl;
}

void trimLeadingWhitespace(std::string& input)
{
	size_t start = input.find_first_not_of(" \t\n\r\f\v");
	if (start != std::string::npos)
        input = input.substr(start);
	else
		input.clear();
}


std::string getInput(const std::string& prompt)
{
	std::string	inputField;

    std::cout << prompt;
    if (!std::getline(std::cin, inputField) || std::cin.eof())
		exit(0);

	trimLeadingWhitespace(inputField);

	while (inputField.empty())
	{
		ft_cout("Input cannot be empty. Please try again.", 1);
		ft_cout(prompt, 0);
		if (!std::getline(std::cin, inputField) || std::cin.eof())
			exit(0);
		trimLeadingWhitespace(inputField);
	}
	return (inputField);
}

void	PhoneBook::ft_add(void)
{
	std::string	input;
	
	input = getInput("Enter first name: ");
	contact[counter % 8].setFirstName(input);

	input = getInput("Enter last name: ");
	contact[counter % 8].setLastName(input);

	input = getInput("Enter nickname: ");
	contact[counter % 8].setNickname(input);

	input = getInput("Enter phone number: ");
	contact[counter % 8].setPhoneNumber(input);

	input = getInput("Enter darkest secret: ");
	contact[counter % 8].setDarkestSecret(input);
	
	counter++;
}

void	PhoneBook::ft_search()
{
	int	displayCounter;
	int	i;

	i = 0;
	if (counter > 7)
		displayCounter = 8;
	else
		displayCounter = counter;
	while (displayCounter)
	{
		std::cout << i << "|"
					<< formatColumn(contact[i].getFirstName(), 10) << "|"
					<< formatColumn(contact[i].getLastName(), 10) << "|"
					<< formatColumn(contact[i].getNickname(), 10) << "|"
					<< std::endl;
		i++;
		displayCounter--;
	}
	while (counter)
	{
		ft_cout("Enter the index number for user's contact info: ", 0);
		std::cin >> i;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.eof())
			exit(0);
		if (std::cin.fail())
		{
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ft_cout("Please enter a valid numeric index.", 1);
        } 
		else if (i >= 0 && i < 8 && i < counter)
		{
			ft_cout("----- CONTACT DETAILS -----", 1);
			ft_cout("Name: ", 0);
			ft_cout(contact[i].getFirstName(), 1);
			ft_cout("Last Name: ", 0);
			ft_cout(contact[i].getLastName(), 1);
			ft_cout("Nickname: ", 0);
			ft_cout(contact[i].getNickname(), 1);
			ft_cout("Phone number: ", 0);
			ft_cout(contact[i].getPhoneNumber(), 1);
			ft_cout("Darkest Secret: ", 0);
			ft_cout(contact[i].getDarkestSecret(), 1);
			ft_cout("----- CONTACT DETAILS -----", 1);
			break ;
		}
	}
}
