/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 01:03:40 by upolat            #+#    #+#             */
/*   Updated: 2025/04/12 02:47:38 by upolat           ###   ########.fr       */
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
	
	if (c == '*')
		return first * second;
	if (c == '/') {
		if (second)
			return first / second;
		throw std::runtime_error("Error");
	}
	if (c == '+')
		return first + second;
	if (c == '-')
		return first - second;
	else
		throw std::runtime_error("Error");
}
