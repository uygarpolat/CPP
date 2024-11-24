/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:20:44 by upolat            #+#    #+#             */
/*   Updated: 2024/11/24 16:05:41 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << "Default Constructor called for " << getType() << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other.getType()) {
    std::cout << "Copy constructor called for " << getType() << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    if (this != &other) {
        _type = other.getType();
    }
    std::cout << "Copy assignment operator constructor called for " << getType() << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Destructor called for WrongAnimal" << std::endl;
}

const std::string &WrongAnimal::getType(void) const {
    return _type;
}

void WrongAnimal::makeSound(void) const {
    std::cout << getType() << " makes random animal noises" << std::endl;
}