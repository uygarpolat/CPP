/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:20:13 by upolat            #+#    #+#             */
/*   Updated: 2025/04/09 20:29:00 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stdexcept>
#include <iostream>

template <class T>
int easyfind(T &x, int val)
{
    typename T::iterator res = std::find(x.begin(), x.end(), val);
    
    if (res == x.end())
        throw std::runtime_error("Value not found");
    return *res;
}

