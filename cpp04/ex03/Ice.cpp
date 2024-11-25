/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:51:08 by upolat            #+#    #+#             */
/*   Updated: 2024/11/26 01:11:26 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
//#include "Character.hpp"

#include <iostream>

Ice::Ice() : AMateria("ice") {}
/*
Ice::Ice(const Ice &other) : data(other.data) {}

Ice &Ice::operator=(const Ice &other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}
*/
Ice::~Ice() {}

AMateria* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}