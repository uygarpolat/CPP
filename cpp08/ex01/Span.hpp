/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:09:58 by upolat            #+#    #+#             */
/*   Updated: 2025/04/10 00:27:38 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>

class Span {
	public:
		Span();
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		Span(unsigned int N);
		
		void				addNumber(int num);
		int					shortestSpan();
		int					longestSpan();
	private:
		unsigned int		_N;
		std::vector<int>	_data;
};