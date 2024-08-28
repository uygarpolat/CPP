/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_phonebook.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 12:30:17 by upolat            #+#    #+#             */
/*   Updated: 2024/08/24 21:15:09 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

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
		PhoneBook(int i)
		{
			counter = i;
		}
};

std::string formatColumn(const std::string& text, int width) {
    if (text.length() > static_cast<std::string::size_type>(width)) {
	
        // Truncate and replace the last character with a dot
        return text.substr(0, width - 1) + ".";
    } else {
        // Return right-aligned text within the specified width
        std::ostringstream oss;
        oss << std::setw(width) << std::right << text;
        return oss.str();
    }
}

void	ft_cout(std::string input, int i)
{
	std::cout << input;
	while (i--)
		std::cout << std::endl;
}


void	ft_add(class PhoneBook *phonebook)
{
	std::cout << "Enter first same: ";
	std::cin >> phonebook->contact[phonebook->counter % 8].FirstName;
	std::cout << "Enter last name: ";
	std::cin >> phonebook->contact[phonebook->counter % 8].LastName;
	std::cout << "Enter nickname: ";
	std::cin >> phonebook->contact[phonebook->counter % 8].Nickname;
	std::cout << "Enter phone number: ";
	std::cin >> phonebook->contact[phonebook->counter % 8].PhoneNumber;
	std::cout << "Enter darkest secret: ";
	std::cin >> phonebook->contact[phonebook->counter % 8].DarkestSecret;
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
		//std::cout << i;
		//ft_cout(" | ", 0);
		//ft_cout(phonebook->contact[i].FirstName, 0);
		//ft_cout(" | ", 0);
		//ft_cout(phonebook->contact[i].LastName, 0);
		//ft_cout(" | ", 0);
		//ft_cout(phonebook->contact[i].Nickname, 0);
		//std::cout << std::endl;
		i++;
		counter--;
	}
	while (1)
	{
		ft_cout("Enter the index number for user's contact info: ", 0);
		std::cin >> i;
		if (i >= 0 && i < 8 && i < phonebook->counter)
		{
			ft_cout(phonebook->contact[i].PhoneNumber, 1);
			break ;
		}
	}
}

int	main(void)
{
	PhoneBook	phonebook(0);
	std::string	userInput;

	while (1)
	{
		ft_cout("Please Enter one of the following 3 commands: ADD, SEARCH, EXIT", 1);
		ft_cout("Your input: ", 0);
		std::cin >> userInput;
		if (userInput.compare("ADD") == 0)
			ft_add(&phonebook);
		else if (userInput.compare("SEARCH") == 0)
			ft_search(&phonebook);
		else if (userInput.compare("EXIT") == 0)
		{
			ft_cout("Closing phonebook!", 1);
			return (0);
		}
		else
			ft_cout("Error: invalid input.", 1);
	}
}
