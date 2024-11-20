/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:18:16 by upolat            #+#    #+#             */
/*   Updated: 2024/11/20 19:14:32 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon)
        : _name(name), _weaponOfA(weapon) {}


HumanA::~HumanA() {
    std::cout << "~ " << _name << " is destroyed! ~" << std::endl;
}

void HumanA::attack() const {
    std::cout << _name << " attacks with their " << _weaponOfA.getType() << std::endl;
}