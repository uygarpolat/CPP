/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:36:00 by upolat            #+#    #+#             */
/*   Updated: 2024/11/24 16:04:53 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << "Default Constructor called for " << getType() << std::endl;
}

Animal::Animal(const Animal &other) : _type(other.getType()) {
        std::cout << "Copy constructor called for " << getType() << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other) {
        _type = other.getType();
    }
    std::cout << "Copy assignment operator constructor called for " << getType() << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Destructor called for Animal" << std::endl;
}

const std::string &Animal::getType(void) const {
    return _type;
}

void Animal::makeSound(void) const {
    std::cout << getType() << " makes random animal noises" << std::endl;
}