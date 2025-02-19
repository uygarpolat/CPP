/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 02:43:09 by upolat            #+#    #+#             */
/*   Updated: 2025/02/19 13:58:11 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

enum Level {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    UNKNOWN,
};

class Harl {
    private:
        void _debug( void );
        void _info( void );
        void _warning( void );
        void _error( void );
    public:
        void complain( std::string level );

};

#endif