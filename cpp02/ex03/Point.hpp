/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:35:44 by upolat            #+#    #+#             */
/*   Updated: 2024/11/22 22:33:32 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
    public:
        Point();
        Point(const Point &other);
        Point &operator=(const Point &other);
        ~Point();
        Fixed getFixed_x( void ) const;
        Fixed getFixed_y( void ) const;
        
        Point(const float float_one, const float float_two);
    private:
        const Fixed _x;
        const Fixed _y;
};

#endif