/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:09:58 by upolat            #+#    #+#             */
/*   Updated: 2025/04/10 17:23:48 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>
#include <iomanip>

class Span {
	public:
		Span();
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		Span(unsigned int N);
		
		void				addNumber(int num);
		void				addNumbers(std::vector<int> newData);
		long long			shortestSpan();
		long long			longestSpan();
	private:
		unsigned int		_N;
		std::vector<int>	_data;
};