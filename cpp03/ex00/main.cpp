/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:16:12 by upolat            #+#    #+#             */
/*   Updated: 2024/11/23 16:36:00 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	vannila;
	ClapTrap	uno("'What is love?'");
	ClapTrap	duo("'Baby dont hurt me!'");

	uno.attack("'Baby dont hurt me!'");
	duo.takeDamage(0);
	duo.beRepaired(9999);
	
	ClapTrap	thisOneIsAngry(duo);

	thisOneIsAngry.attack("'What is love?'");
	uno.takeDamage(10);
	uno.beRepaired(10);

	for (int i = 0; i < 10; i++)
		thisOneIsAngry.attack("'What is love?'");

	uno.takeDamage(1);
	thisOneIsAngry.beRepaired(1);
	return 0;
}


/*
int main(void) {
    
    ClapTrap beast("Beast");

    beast.attack("The Punisher");
    beast.attack("The Punisher");

    beast.attack("The Punisher");
    beast.attack("The Punisher");
    beast.attack("The Punisher");
    beast.attack("The Punisher");
    beast.attack("The Punisher");
    beast.attack("The Punisher");
    beast.beRepaired(3);
    beast.takeDamage(13);
    beast.takeDamage(12);
    beast.beRepaired(3);
    beast.beRepaired(3);
    return 0;
}
*/