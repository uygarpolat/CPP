/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:31:14 by upolat            #+#    #+#             */
/*   Updated: 2025/03/05 00:16:41 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    if (this != &other) {
		(void)other;
    }
    return *this;
}

ScalarConverter::~ScalarConverter() {}

int ScalarConverter::IsOverflow(const double &d)
{
		if (d < nextafter(nextafter(-FLT_MAX, 0), -FLT_MAX) || nextafter(nextafter(FLT_MAX, 0), FLT_MAX) < d)
    		return 3;
		if (d < nextafter(nextafter(INT_MIN, 0), INT_MIN) || nextafter(nextafter(INT_MAX, 0), INT_MAX) < d)
    		return 2;
		if (d < nextafter(nextafter(CHAR_MIN, 0), CHAR_MIN) || nextafter(nextafter(CHAR_MAX, 0), CHAR_MAX) < d)
    		return 1;	
		return 0;
}

void ScalarConverter::handleChar(const char &c, const int &overflow)
{
	std::cout << "char: ";
	if (overflow > 0)
		std::cout << "impossible" << std::endl;
	else
	{
		if (std::isprint(c))
		{
			if (!overflow)
				std::cout << "'";
			std::cout << c;
			if (!overflow)
				std::cout << "'";
			std::cout << std::endl;
		}
		else
			std::cout << "Not Displayable" << std::endl;
	}		
}

int ScalarConverter::getNativeType(std::string &input) {

	if (!input.compare("+inf") || !input.compare("-inf") || !input.compare("nan"))
		return DOUBLE;
	if (!input.compare("+inff") || !input.compare("-inff") || !input.compare("nanf"))
		return FLOAT;

	if (input == "")
		return NONE;

	int len = input.length();
	if (len == 1) {
		if (isdigit(input[0]))
			return INTEGER;
		else
			return CHAR;
	}

	if (input.find_first_of("0123456789") == std::string::npos)
		return NONE;
	
	std::string arg = input;
	if (len && (input[0] == '-' || input[0] == '+'))
		arg = input.substr(1, --len);

	int type = INTEGER;

	for (char& c : arg) {
	
		if (!isdigit(c)) {
			if (c == '.')
			{
				if (type == INTEGER)
					type = DOUBLE;
				else
					return NONE;
			}
			else if (c == 'f')
			{
				if (type == DOUBLE)
					type = FLOAT;
				else
					return NONE;
			}
			else
				return NONE;
		}
	}
	return type;
}

void ScalarConverter::printAllTypes(char valueChar, int valueInt, float valueFloat, double valueDouble, int overflow) {
	handleChar(valueChar, overflow);
	if (overflow > 1)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << valueInt << std::endl;

	std::cout << std::fixed << std::setprecision(1);
		
	if (overflow > 2)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << valueFloat << "f" << std::endl;
	std::cout << "double: " << valueDouble << std::endl;
}

void ScalarConverter::convert(std::string input) {
    
	int		native_type = getNativeType(input);
	
	int		valueInt;
	float	valueFloat;
	double	valueDouble;
	char	valueChar;
	int		overflow;
	
	switch(native_type) {
		case INTEGER: 
			valueInt = std::stoi(input);
			
			valueFloat = static_cast<float>(valueInt);
			valueDouble = static_cast<double>(valueInt);
			valueChar = static_cast<char>(valueInt);
			
			overflow = IsOverflow(std::stod(input));
			printAllTypes(valueChar, valueInt, valueFloat, valueDouble, overflow);
			break;
		case CHAR:
			valueChar = input[0];

			valueFloat = static_cast<float>(valueChar);
			valueDouble = static_cast<double>(valueChar);
			valueInt = static_cast<int>(valueChar);

			overflow = -1;
			printAllTypes(valueChar, valueInt, valueFloat, valueDouble, overflow);
			break;
		case FLOAT:
			valueFloat = std::stof(input);

			valueInt = static_cast<int>(valueFloat);
			valueDouble = static_cast<double>(valueFloat);
			valueChar = static_cast<char>(valueFloat);
			
			overflow = IsOverflow(std::stod(input));
			std::cout << "overflow: " << overflow << std::endl;
			printAllTypes(valueChar, valueInt, valueFloat, valueDouble, overflow);
			break;
		case DOUBLE:
			valueDouble = std::stod(input);
			std::cout << valueDouble << std::endl;
			valueInt = static_cast<int>(valueDouble);
			valueFloat = static_cast<float>(valueDouble);
			std::cout << valueFloat << std::endl;
			valueChar = static_cast<char>(valueDouble);
			
			overflow = IsOverflow(std::stod(input));
			printAllTypes(valueChar, valueInt, valueFloat, valueDouble, overflow);
			break;
		default:
			std::cout << "Invalid input" << std::endl;
	}
}