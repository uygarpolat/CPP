/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 01:03:40 by upolat            #+#    #+#             */
/*   Updated: 2025/04/25 21:42:19 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _data(), _argv("") {}

RPN::RPN(const RPN &other) : _data(other._data), _argv(other._argv) {}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		_data = other._data;
		_argv = other._argv;
	}
	return *this;
}

RPN::~RPN() {}

RPN::RPN(std::string argv) : _data(), _argv(argv) {}

int RPN::parseRpn() {

	// Erroring out if unary minus is encountered
	for (size_t i = 0; i + 1 < _argv.size(); ++i) {
        if ((_argv[i] == '-'  || _argv[i] == '+') && isdigit(_argv[i+1]))
            throw std::runtime_error("Error");
    }
	
	for (auto c : _argv) {
		if (isspace(c))
			continue;
		if (isdigit(c))
			_data.push(static_cast<int>(c - '0'));
		else if (strchr("+-/*", c))
			_data.push(_calculate(c));
		else
			throw std::runtime_error("Error");
	}
	if (_data.size() != 1)
		throw std::runtime_error("Error");
	return _data.top();
}

int RPN::_calculate(const char c) {
	if (_data.size() < 2)
		throw std::runtime_error("Error");
	
	int second = _data.top();
	_data.pop();
	int first = _data.top();
	_data.pop();

	if (c == '/' && !second)
		throw std::runtime_error("Error");
		
	switch (c) {
		case '*': return first * second;
		case '/': return first / second;
		case '+': return first + second;
		case '-': return first - second;
		default:
			throw std::runtime_error("Error");
	}
}
