/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:31:51 by upolat            #+#    #+#             */
/*   Updated: 2024/11/29 14:33:27 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

enum nativeType {
	CHAR,
	INTEGER,
	FLOAT,
	DOUBLE,
	NONE
  };

class ScalarConverter {
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

		class ImpossibleException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

		class NonDisplayableException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

        static void convert(std::string input);
};