/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:31:14 by upolat            #+#    #+#             */
/*   Updated: 2025/03/03 15:35:58 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    if (this != &other) {
		
    }
    return *this;
}

ScalarConverter::~ScalarConverter() {}

int getNativeType(std::string &input) {

	if (!input.compare("+inf") || !input.compare("-inf") || !input.compare("nan"))
		return PSEUDO_DOUBLE;
	if (!input.compare("+inff") || !input.compare("-inff") || !input.compare("nanf"))
		return PSEUDO_FLOAT;

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

void ScalarConverter::convert(std::string input) {
    int native_type = getNativeType(input);
	
	int value_int;
	float value_float;
	double value_double;
	char value_char;
	
	switch(native_type) {
		case INTEGER: 
		
			value_int = std::stoi(input);
			
			value_float = static_cast<float>(value_int);
			value_double = static_cast<double>(value_int);
			value_char = static_cast<char>(value_int);
		
			if (!std::isprint(value_char))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: '" << value_char << "'" << std::endl;
		
			std::cout << "int: " << value_int << std::endl;
			std::cout << "float: " << value_float << "f" << std::endl;
			std::cout << "double: " << value_double << std::endl;
			break;
		
		case CHAR:
			value_char = input[0];

			value_float = static_cast<float>(value_char);
			value_double = static_cast<double>(value_char);
			value_int = static_cast<int>(value_char);
			
			if (!std::isprint(value_char))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: '" << value_char << "'" << std::endl;
		
			std::cout << "int: " << value_int << std::endl;
			std::cout << "float: " << value_float << "f" << std::endl;
			std::cout << "double: " << value_double << std::endl;
			break;
		case FLOAT:
			value_float = std::stof(input);

			value_int = static_cast<int>(value_float);
			value_double = static_cast<double>(value_float);
			value_char = static_cast<char>(value_float);
			
			if (!std::isprint(value_char))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: '" << value_char << "'" << std::endl;
		
			std::cout << "int: " << value_int << std::endl;
			std::cout << "float: " << value_float << "f" << std::endl;
			std::cout << "double: " << value_double << std::endl;
			break;
		case DOUBLE:
			value_double = std::stod(input);

			value_int = static_cast<int>(value_double);
			value_float = static_cast<float>(value_double);
			value_char = static_cast<char>(value_double);
			
			if (!std::isprint(value_char))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: '" << value_char << "'" << std::endl;
		
			std::cout << "int: " << value_int << std::endl;
			std::cout << "float: " << value_float << "f" << std::endl;
			std::cout << "double: " << value_double << std::endl;
			break;

		
		case NONE:
			std::cout << "Invalid input" << std::endl;
		default:
			break;
	}
}