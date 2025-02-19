/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:37:54 by upolat            #+#    #+#             */
/*   Updated: 2025/02/19 13:57:29 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

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