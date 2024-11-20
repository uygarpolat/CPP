/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:24:26 by upolat            #+#    #+#             */
/*   Updated: 2024/11/20 19:03:29 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
    : _name(name), _weaponOfB(nullptr) {}

void HumanB::setWeapon(Weapon& weapon) {
    _weaponOfB = &weapon;
}

void HumanB::attack() const {
    if (_weaponOfB) {
        std::cout << _name << " attacks with their " << _weaponOfB->getType() << std::endl;
    } else {
        std::cout << _name << " tries to attack without a weapon" << std::endl;
    }
}

HumanB::~HumanB() {
    std::cout << "~ " << _name << " is destroyed! ~" << std::endl;
}