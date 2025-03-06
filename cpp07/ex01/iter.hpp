/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:07:48 by upolat            #+#    #+#             */
/*   Updated: 2025/03/06 19:03:50 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"

template <class T> void print(T &x)
{
	std::cout << x << std::endl;
}

template <class T> void iter(T *arr, int &len, void (*func)(T &elem))
{
	for (int i = 0; i < len; i++)
		(func)(arr[i]);
}