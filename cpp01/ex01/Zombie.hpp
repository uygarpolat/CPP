/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 01:23:35 by upolat            #+#    #+#             */
/*   Updated: 2024/11/20 01:23:38 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
    public:
        void announce( void );

        Zombie(std::string);
        ~Zombie();
    private:
        std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif