/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:20:28 by upolat            #+#    #+#             */
/*   Updated: 2024/11/24 15:23:16 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    _type = "WrongCat";
    std::cout << "Default Constructor called for " << getType() << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) {
    _type = other.getType();
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
    std::cout << "Destructor called for " << getType() << std::endl;
}

void WrongCat::makeSound(void) const {
    std::cout << getType() << " says MEOW" << std::endl;
}