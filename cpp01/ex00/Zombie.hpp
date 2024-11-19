/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:00:30 by upolat            #+#    #+#             */
/*   Updated: 2024/11/19 22:00:31 by upolat           ###   ########.fr       */
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

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif