/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:37:18 by upolat            #+#    #+#             */
/*   Updated: 2024/11/24 20:52:53 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    _type = "Dog";
    std::cout << "Default Constructor called for " << getType() << std::endl;
    _brain = new Brain();
}

Dog::Dog(const Dog &other) {
    _type = other.getType();
    std::cout << "Copy constructor called for " << getType() << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        _type = other.getType();
    }
    std::cout << "Copy assignment operator constructor called for " << getType() << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "Destructor called for Dog" << std::endl;
    delete _brain;
}

void Dog::makeSound(void) const {
    std::cout << getType() << " says BARK" << std::endl;
}