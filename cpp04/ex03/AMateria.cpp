/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:36:46 by upolat            #+#    #+#             */
/*   Updated: 2024/11/26 18:08:09 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : _type("UnknownType") {}

AMateria::AMateria(const std::string  &type) : _type(type) {}

AMateria::AMateria(const AMateria &other) : _type("") {
    (void)other;
}

AMateria &AMateria::operator=(const AMateria &other) {
    (void)other;
    return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "* uses AMateria on " << target.getName() << " *" << std::endl;
}