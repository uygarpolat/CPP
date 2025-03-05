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
#include <cfloat>
#include <iomanip>

enum nativeType {
	CHAR,
	INTEGER,
	FLOAT,
	DOUBLE,
	NONE
  };

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

		static int IsOverflow(const double &d);
		static void handleChar(const char &c, const int &overflow, const int &pseudoFlag);
		static int getNativeType(std::string &input);
		static void printAllTypes(char valueChar, int valueInt,
			float valueFloat, double valueDouble, int overflow);
	public:
        static void convert(std::string input);
};
