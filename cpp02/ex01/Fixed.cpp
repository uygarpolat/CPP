/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:29:38 by upolat            #+#    #+#             */
/*   Updated: 2024/11/22 01:55:56 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fraction = 8;

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    _value = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const float floatValue) {
    _value = std::round(floatValue * std::pow(2, _fraction));
}

Fixed::Fixed(const int intValue) {
    //_value = intValue * std::pow(2, _fraction);
    _value = _fraction << intValue;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}
void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

float Fixed::toFloat( void ) const {
    return (getRawBits() / std::pow(2, _fraction));
    //return (getRawBits() >> _fraction);
}

int Fixed::toInt( void ) const {
    //return (std::round(getRawBits() / std::pow(2, _fraction)));
    return (getRawBits() >> _fraction);
}
