/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:46:09 by upolat            #+#    #+#             */
/*   Updated: 2025/04/26 13:07:35 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <stdexcept>
#include <string.h>

class RPN {
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		RPN(std::string argv);
		int parseRpn();
	private:
		std::stack<int>	_data;
		std::string		_argv;
		int _calculate(const char c);
};