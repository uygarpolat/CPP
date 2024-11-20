/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 01:23:15 by upolat            #+#    #+#             */
/*   Updated: 2024/11/20 01:23:16 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *Hordes = new Zombie[N];
    
    for (int i = 0; i < N; i++)
        Hordes[i].setName(name + std::to_string(i + 1));
    return Hordes;
}