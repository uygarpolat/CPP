/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 01:25:08 by upolat            #+#    #+#             */
/*   Updated: 2024/11/20 01:25:23 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main ( void )
{
    int hordeSize = 7;
    std::string zombieName = "zOmBiE-";
    
    Zombie *myHordes = zombieHorde(hordeSize, zombieName);

    for (int i = 0; i < hordeSize; i++)
        myHordes[i].announce();
    delete[] myHordes;

    return 0;
}
