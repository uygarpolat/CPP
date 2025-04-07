/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:34:11 by upolat            #+#    #+#             */
/*   Updated: 2025/04/07 21:01:27 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>

template <typename T> class Array {
	private:
		T*				_arr;
		unsigned int	_size;
	public:
		Array();
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		T &operator[](unsigned int index);
		Array(unsigned int n);
		unsigned int size() const;
};

#include "Array.tpp"
