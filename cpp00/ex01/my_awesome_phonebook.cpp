/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_phonebook.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 12:30:17 by upolat            #+#    #+#             */
/*   Updated: 2024/09/04 15:45:20 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>

class Contact
{
	private:
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_Nickname;
		std::string	_PhoneNumber;
		std::string	_DarkestSecret;

	public:
		void setFirstName(std::string FirstName)
		{
			_FirstName = FirstName;
		}
		std::string getFirstName()
		{
			return (_FirstName);
		}
	public:
		void setLastName(std::string LastName)
		{
			_LastName = LastName;
		}
		std::string getLastName()
		{
			return (_LastName);
		}
	public:
		void setNickname(std::string Nickname)
		{
			_Nickname = Nickname;
		}
		std::string getNickname()
		{
			return (_Nickname);
		}
	public:
		void setPhoneNumber(std::string PhoneNumber)
		{
			_PhoneNumber = PhoneNumber;
		}
		std::string getPhoneNumber()
		{
			return (_PhoneNumber);
		}
	public:
		void setDarkestSecret(std::string DarkestSecret)
		{
			_DarkestSecret = DarkestSecret;
		}
		std::string getDarkestSecret()
		{
			return (_DarkestSecret);
		}
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

void	ft_add(class PhoneBook *phonebook)
{

	// Makes sure to ignore newline characters from previous reads.
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//getInput("Enter first name: ", phonebook->contact[phonebook->counter % 8].setFirstName());
	//getInput("Enter last name: ", phonebook->contact[phonebook->counter % 8].setLastName());
	//getInput("Enter nickname: ", phonebook->contact[phonebook->counter % 8].setNickname());
	//getInput("Enter phone number: ", phonebook->contact[phonebook->counter % 8].setPhoneNumber());
	//getInput("Enter darkest secret: ", phonebook->contact[phonebook->counter % 8].setDarkestSecret());

	std::string	input;
	input = getInput("Enter first name: ");
    phonebook->contact[phonebook->counter % 8].setFirstName(input);

    input = getInput("Enter last name: ");
    phonebook->contact[phonebook->counter % 8].setLastName(input);

    input = getInput("Enter nickname: ");
    phonebook->contact[phonebook->counter % 8].setNickname(input);

    input = getInput("Enter phone number: ");
    phonebook->contact[phonebook->counter % 8].setPhoneNumber(input);

    input = getInput("Enter darkest secret: ");
    phonebook->contact[phonebook->counter % 8].setDarkestSecret(input);
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
					<< formatColumn(phonebook->contact[i].getFirstName(), 10) << "|"
					<< formatColumn(phonebook->contact[i].getLastName(), 10) << "|"
					<< formatColumn(phonebook->contact[i].getNickname(), 10) << "|"
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
			ft_cout(phonebook->contact[i].getFirstName(), 1);
			ft_cout("Last Name: ", 0);
			ft_cout(phonebook->contact[i].getLastName(), 1);
			ft_cout("Nickname: ", 0);
			ft_cout(phonebook->contact[i].getNickname(), 1);
			ft_cout("Phone number: ", 0);
			ft_cout(phonebook->contact[i].getPhoneNumber(), 1);
			ft_cout("Darkest Secret: ", 0);
			ft_cout(phonebook->contact[i].getDarkestSecret(), 1);
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
