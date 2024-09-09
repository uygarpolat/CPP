/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:44:34 by upolat            #+#    #+#             */
/*   Updated: 2024/09/09 16:04:51 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

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
			phonebook.ft_add(&phonebook);
		else if (userInput.compare("SEARCH") == 0)
			phonebook.ft_search(&phonebook);
		else if (userInput.compare("EXIT") == 0)
			return (0);
		else
			std::cout << "Error: invalid input." << std::endl;
	}
}
