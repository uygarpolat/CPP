/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:31:14 by upolat            #+#    #+#             */
/*   Updated: 2025/03/03 09:34:29 by upolat           ###   ########.fr       */
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

const char *ScalarConverter::ImpossibleException::what() const noexcept {
    return "impossible\n";
}

const char *ScalarConverter::NonDisplayableException::what() const noexcept {
    return "Non displayable\n";
}

int getNativeType(std::string &input) {

	if (!input.compare("+inf") || !input.compare("-inf") || !input.compare("nan"))
		return DOUBLE;
	if (!input.compare("+inff") || !input.compare("-inff") || !input.compare("nanf"))
		return FLOAT;

	if (input == "")
		return NONE;

	if (input.find_first_of("0123456789") == std::string::npos)
		return NONE;
	
	int len = input.length();
	if (len == 1) {
		if (isdigit(input[0]))
			return INTEGER;
		else
			return CHAR;
	}

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

// void handleInteger(std::string input) {
// 	try {
// 		value_int = stoi(input);
// 	}
// 	catch {
// 		throw ImpossibleException()
// 	}
// }

void ScalarConverter::convert(std::string input) {
    int native_type = getNativeType(input);
	int value_int;
	float value_float;
	double value_double;
	char value_char;
	
	switch(native_type) {
		case INTEGER: {
			try {
				value_int = std::stoi(input);
			}
			catch (const std::out_of_range &e) {
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				break;
			}
		
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
		}

		case CHAR:
			break;
		case NONE:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
		default:
			break;
	}
}