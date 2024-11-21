/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 02:43:09 by upolat            #+#    #+#             */
/*   Updated: 2024/11/21 12:36:04 by upolat           ###   ########.fr       */
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