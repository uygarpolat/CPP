/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:05:36 by upolat            #+#    #+#             */
/*   Updated: 2024/11/19 21:05:37 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int		main( void )
{
    Zombie zombie("originalZombie");
    Zombie *heapZombie;

    zombie.announce();

    heapZombie = newZombie("heapZombie");
    heapZombie->announce();

    randomChump("stackZombie");
    delete heapZombie;

    return 0;
}