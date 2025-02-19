/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:26:11 by upolat            #+#    #+#             */
/*   Updated: 2025/02/19 13:30:41 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

const std::string& Weapon::getType() const {
    return (_type);
}

void    Weapon::setType(std::string typeNew) {
    _type = typeNew;
}

Weapon::Weapon(const std::string &type) {
    setType(type);
};

Weapon::~Weapon() {
    std::cout << "~ " << _type << " is destroyed! ~" << std::endl;
}