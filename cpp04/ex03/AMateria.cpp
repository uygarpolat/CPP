/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:36:46 by upolat            #+#    #+#             */
/*   Updated: 2024/11/26 01:30:14 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : _type("UnknownType") {}

AMateria::AMateria(const std::string  &type) : _type(type) {}
/*
AMateria::AMateria(const AMateria &other) : data(other.data) {}

AMateria &AMateria::operator=(const AMateria &other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}
*/
AMateria::~AMateria() {}

std::string const &AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "* uses AMateria on " << target.getName() << " *" << std::endl;
}
