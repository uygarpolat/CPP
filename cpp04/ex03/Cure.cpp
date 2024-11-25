/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:12:15 by upolat            #+#    #+#             */
/*   Updated: 2024/11/26 01:10:42 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}
/*
Cure::Cure(const Cure &other) : data(other.data) {}

Cure &Cure::operator=(const Cure &other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}
*/
Cure::~Cure() {}

AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}