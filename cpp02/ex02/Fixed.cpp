/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:29:38 by upolat            #+#    #+#             */
/*   Updated: 2024/11/22 20:19:07 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fraction = 8;

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed &other)
{
    setRawBits(other.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other)
        setRawBits(other.getRawBits());
    return *this;
}

Fixed::~Fixed() {}

Fixed::Fixed(const float floatValue) {
    if (floatValue > (INT_MAX >> _fraction) || floatValue < (INT_MIN >> _fraction))
        throw std::overflow_error("Floating-point value too large for fixed-point format");
    setRawBits(std::round(floatValue * (1 << _fraction)));
}

Fixed::Fixed(const int intValue) {
    if (intValue > (INT_MAX >> _fraction) || intValue < (INT_MIN >> _fraction))
        throw std::overflow_error("Integer value too large for fixed-point format");
    setRawBits(intValue << _fraction);
}

int Fixed::getRawBits( void ) const {
    return _value;
}
void Fixed::setRawBits( int const raw ) {
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

bool Fixed::operator<(const Fixed &other) const {
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>(const Fixed &other) const {
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->getRawBits() >= other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    result.setRawBits((this->getRawBits() * other.getRawBits()) >> _fraction);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    if (other.getRawBits() == 0)
        throw std::runtime_error("Division by zero");
    Fixed result;
    result.setRawBits((this->getRawBits() << _fraction) / other.getRawBits());
    return result;
}

Fixed &Fixed::operator++() {
    this->_value += 1;
    return *this;
}

Fixed &Fixed::operator--() {
    this->_value -= 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->_value += 1;
    return temp;
}
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->_value -= 1;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}