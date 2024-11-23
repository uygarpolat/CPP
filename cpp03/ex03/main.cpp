/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:16:12 by upolat            #+#    #+#             */
/*   Updated: 2024/11/24 01:25:25 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	uno("WhatIsLove");
	DiamondTrap	duo("BabyDontHurtMe");

	uno.attack("BabyDontHurtMe");
	duo.takeDamage(0);
	duo.beRepaired(9999);
	
	DiamondTrap	thisOneIsAngry(duo);

	thisOneIsAngry.attack("WhatIsLove");
	uno.takeDamage(10);
	uno.beRepaired(10);

	for (int i = 0; i < 10; i++)
		thisOneIsAngry.attack("WhatIsLove");

	uno.takeDamage(1);
	thisOneIsAngry.beRepaired(1);

	thisOneIsAngry.whoAmI();

	DiamondTrap("NoooMooo");

	DiamondTrap nameless;
	nameless.whoAmI();

	return 0;
}