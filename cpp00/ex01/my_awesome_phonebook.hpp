/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_phonebook.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:02:41 by upolat            #+#    #+#             */
/*   Updated: 2024/09/09 16:04:23 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MY_AWESOME_PHONEBOOK_HPP__
# define __MY_AWESOME_PHONEBOOK_HPP__

# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>
# include <limits>

void	ft_cout(std::string input, int i);

class Contact {
	private:
		std::string _FirstName;
		std::string _LastName;
		std::string _Nickname;
		std::string _PhoneNumber;
		std::string _DarkestSecret;

	public:
		void setFirstName(std::string& FirstName);
		std::string getFirstName() const;
	
		void setLastName(std::string& LastName);
		std::string getLastName() const;

		void setNickname(std::string& Nickname);
		std::string getNickname() const;

		void setPhoneNumber(std::string& PhoneNumber);
		std::string getPhoneNumber() const;

		void setDarkestSecret(std::string& DarkestSecret);
		std::string getDarkestSecret() const;
};

class PhoneBook {
	private:
		Contact contact[8];
		int counter;

	public:
		PhoneBook();
		~PhoneBook();

		void	ft_add(class PhoneBook *phonebook);
		void	ft_search(class PhoneBook *phonebook);
};

#endif