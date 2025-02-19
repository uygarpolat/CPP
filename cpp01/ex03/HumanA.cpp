/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:18:16 by upolat            #+#    #+#             */
/*   Updated: 2025/02/19 13:30:13 by upolat           ###   ########.fr       */
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