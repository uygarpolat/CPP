/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:07:48 by upolat            #+#    #+#             */
/*   Updated: 2025/04/08 11:44:24 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"

template <class T>
void iter(T *arr, size_t len, void (*func)(T &elem))
{
	for (size_t i = 0; i < len; i++)
		(func)(arr[i]);
}

template <class T>
void iter(T *arr, size_t len, void (*func)(T const &elem))
{
	for (size_t i = 0; i < len; i++)
		(func)(arr[i]);
}
