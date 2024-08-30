/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_phonebook.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 12:30:17 by upolat            #+#    #+#             */
/*   Updated: 2024/08/30 13:56:06 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>

class Contact
{
	public:
		std::string	FirstName;
		std::string	LastName;
		std::string	Nickname;
		std::string	PhoneNumber;
		std::string	DarkestSecret;
};

class PhoneBook
{
	public:
		Contact contact[8];
		int		counter;
		
		PhoneBook() : counter(0)
		{
			std::cout << "PhoneBook created.\n";
		}

    	~PhoneBook()
		{
			std::cout << "PhoneBook destroyed.\n";
		}
};

std::string formatColumn(const std::string& text, int width)
{
    if (text.length() > static_cast<std::string::size_type>(width))
        return text.substr(0, width - 1) + ".";
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


void getInput(const std::string& prompt, std::string& inputField)
{
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
}

void	ft_add(class PhoneBook *phonebook)
{

	// Makes sure to ignore newline characters from previous reads.
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getInput("Enter first name: ", phonebook->contact[phonebook->counter % 8].FirstName);
	getInput("Enter last name: ", phonebook->contact[phonebook->counter % 8].LastName);
	getInput("Enter nickname: ", phonebook->contact[phonebook->counter % 8].Nickname);
	getInput("Enter phone number: ", phonebook->contact[phonebook->counter % 8].PhoneNumber);
	getInput("Enter darkest secret: ", phonebook->contact[phonebook->counter % 8].DarkestSecret);
	phonebook->counter++;
}

void	ft_search(class PhoneBook *phonebook)
{
	int	counter;
	int	i;

	i = 0;
	if (phonebook->counter > 7)
		counter = 8;
	else
		counter = phonebook->counter;
	while (counter)
	{
		std::cout << i << "|"
					<< formatColumn(phonebook->contact[i].FirstName, 10) << "|"
					<< formatColumn(phonebook->contact[i].LastName, 10) << "|"
					<< formatColumn(phonebook->contact[i].Nickname, 10) << "|"
					<< std::endl;
		i++;
		counter--;
	}
	while (phonebook->counter)
	{
		ft_cout("Enter the index number for user's contact info: ", 0);
		std::cin >> i;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.fail())
		{
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ft_cout("Please enter a valid numeric index.", 1);
        } 
		else if (i >= 0 && i < 8 && i < phonebook->counter)
		{
			ft_cout("-----", 1);
			ft_cout("Name: ", 0);
			ft_cout(phonebook->contact[i].FirstName, 1);
			ft_cout("Last Name: ", 0);
			ft_cout(phonebook->contact[i].LastName, 1);
			ft_cout("Nickname: ", 0);
			ft_cout(phonebook->contact[i].Nickname, 1);
			ft_cout("Phone number: : ", 0);
			ft_cout(phonebook->contact[i].PhoneNumber, 1);
			ft_cout("Darkest Secret: ", 0);
			ft_cout(phonebook->contact[i].DarkestSecret, 1);
			ft_cout("-----", 1);
			break ;
		}
	}
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	userInput;

	while (true)
	{
		ft_cout("Please Enter one of the following 3 commands: ADD, SEARCH, EXIT", 1);
		ft_cout("Your input: ", 0);
		if (!std::getline(std::cin, userInput) || std::cin.eof())
			exit(0);
		if (userInput.compare("ADD") == 0)
			ft_add(&phonebook);
		else if (userInput.compare("SEARCH") == 0)
			ft_search(&phonebook);
		else if (userInput.compare("EXIT") == 0)
			return (0);
		else
			ft_cout("Error: invalid input.", 1);
	}
}
