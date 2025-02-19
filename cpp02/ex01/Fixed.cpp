/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:29:38 by upolat            #+#    #+#             */
/*   Updated: 2025/02/19 20:11:37 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fraction = 8;

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    setRawBits(other.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        setRawBits(other.getRawBits());
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called" << std::endl;
    if (floatValue > (INT_MAX >> _fraction) || floatValue < (INT_MIN >> _fraction))
        throw std::overflow_error("Floating-point value too large for fixed-point format");
    setRawBits(std::round(floatValue * (1 << _fraction)));
}

Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called" << std::endl;
    if (intValue > (INT_MAX >> _fraction) || intValue < (INT_MIN >> _fraction))
        throw std::overflow_error("Integer value too large for fixed-point format");
    setRawBits(intValue << _fraction);
}

int Fixed::getRawBits( void ) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return _value;
}
void Fixed::setRawBits( int const raw ) {
    //std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

float Fixed::toFloat( void ) const {
    return static_cast<float>(getRawBits()) / (1 << _fraction);
}

int Fixed::toInt( void ) const {
    return (getRawBits() + (1 << (_fraction - 1))) >> _fraction;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
