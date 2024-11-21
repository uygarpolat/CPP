/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 00:37:54 by upolat            #+#    #+#             */
/*   Updated: 2024/11/21 02:28:34 by upolat           ###   ########.fr       */
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