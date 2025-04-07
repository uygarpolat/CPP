/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:35:52 by upolat            #+#    #+#             */
/*   Updated: 2025/04/07 11:17:36 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define GREEN "\033[32m"
#define DEFAULT "\033[39m"

class Base
{
	public:
		virtual	~Base();
};

Base *generate();
void identify(Base *p);
void identify(Base &p);