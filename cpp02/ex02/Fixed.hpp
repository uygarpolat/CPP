/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:29:41 by upolat            #+#    #+#             */
/*   Updated: 2024/11/23 19:20:51 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        Fixed(const int intValue);
        Fixed(const float floatValue);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        
        bool operator <  (const Fixed &other) const;
        bool operator >  (const Fixed &other) const;
        bool operator <= (const Fixed &other) const;
        bool operator >= (const Fixed &other) const;
        bool operator == (const Fixed &other) const;
        bool operator != (const Fixed &other) const;

        Fixed operator + (const Fixed &other) const;
        Fixed operator - (const Fixed &other) const;
        Fixed operator * (const Fixed &other) const;
        Fixed operator / (const Fixed &other) const;

        Fixed &operator ++ ();
        Fixed &operator -- ();
        Fixed operator ++ (int);
        Fixed operator -- (int);

        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
    
    private:
        int _value;
        static const int _fraction;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif