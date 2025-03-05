/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:36:11 by upolat            #+#    #+#             */
/*   Updated: 2025/03/06 00:53:05 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base *generate(void) {

	int num = rand() % 3;
	switch(num) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return nullptr;
	}
}

void identify(Base *p)
{
	if (!p)
		std::cout << "Type: null pointer" << std::endl;
	else if (dynamic_cast<A *>(p))
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Type: B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Type: C" << std::endl;
	else
		std::cout << "Type is not A, B, or C" << std::endl;
}

void identify(Base &p) {
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "Type: A" << std::endl;
        return;
    } catch (std::bad_cast &) {}

    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "Type: B" << std::endl;
        return;
    } catch (std::bad_cast &) {}

    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "Type: C" << std::endl;
        return;
    } catch (std::bad_cast &) {}

    std::cout << "Type is not A, B, or C" << std::endl;
}
