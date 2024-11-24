/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:36:42 by upolat            #+#    #+#             */
/*   Updated: 2024/11/24 16:05:24 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    _type = "Cat";
    std::cout << "Default Constructor called for " << getType() << std::endl;
}

Cat::Cat(const Cat &other) {
    _type = other.getType();
    std::cout << "Copy constructor called for " << getType() << std::endl;

}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        _type = other.getType();
    }
    std::cout << "Copy assignment operator constructor called for " << getType() << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "Destructor called for Cat" << std::endl;
}

void Cat::makeSound(void) const {
    std::cout << getType() << " says MEOW" << std::endl;
}