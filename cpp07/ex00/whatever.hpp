/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:58:13 by upolat            #+#    #+#             */
/*   Updated: 2025/03/06 10:13:31 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <class T> void swap(T &x, T &y)
{
	T temp;

	temp = x;
	x = y;
	y = temp;
}

template <class T> T max(const T x, const T y)
{
	return x > y ? x : y;
}

template <class T> T min(const T x, const T y)
{
	return x < y ? x : y;
}
