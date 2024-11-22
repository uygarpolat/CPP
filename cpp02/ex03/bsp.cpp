/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:41:15 by upolat            #+#    #+#             */
/*   Updated: 2024/11/23 00:13:53 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
A point is inside a triangle if and only if it lies on the same side of 
each edge of the triangle as the vertex opposite that edge. This function 
checks this condition for all three edges of the triangle.
*/

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    
    Point const vertices[3] = {a, b, c};

    Fixed point_x = point.getFixed_x();
    Fixed point_y = point.getFixed_y();

    for (int i = 0; i < 3; i++) {
        
        Fixed x1 = vertices[i % 3].getFixed_x();
        Fixed y1 = vertices[i % 3].getFixed_y();

        Fixed x2 = vertices[(i + 1) % 3].getFixed_x();
        Fixed y2 = vertices[(i + 1) % 3].getFixed_y();

        Fixed a1 = vertices[(i + 2) % 3].getFixed_x();
        Fixed b1 = vertices[(i + 2) % 3].getFixed_y();

        Fixed A = y2 - y1;
        Fixed B = x1 - x2;
        Fixed C = x2 * y1 - x1 * y2;

        Fixed result1 = (A * a1 + B * b1 + C);
        Fixed result2 = (A * point_x + B * point_y + C);

        if (result1 * result2 <= 0)
            return false;
    }
    return true;
}