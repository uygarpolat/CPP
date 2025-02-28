/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:20:28 by upolat            #+#    #+#             */
/*   Updated: 2025/02/28 12:52:23 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    _type = "WrongCat";
    std::cout << "Default Constructor called for " << getType() << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    std::cout << "Copy constructor called for " << getType() << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    if (this != &other) {
        _type = other.getType();
    }
    std::cout << "Copy assignment operator constructor called for " << getType() << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "Destructor called for WrongCat" << std::endl;
}

void WrongCat::makeSound(void) const {
    std::cout << getType() << " says MEOW" << std::endl;
}