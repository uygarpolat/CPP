/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:36:51 by upolat            #+#    #+#             */
/*   Updated: 2024/11/23 14:09:33 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point::Point(const float float_one, const float float_two) : _x(float_one), _y(float_two) {}
/*
Point &Point::operator=(const Point &other) {
    if (this != &other) {
        // Cannot implement it due to const attributes. Therefore it is marked as deleted in the class declaration.
    }
    return *this;
}
*/
Point::~Point() {}

Fixed Point::getFixed_x( void ) const {
    return _x;
}
Fixed Point::getFixed_y( void ) const {
    return _y;
}