/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:15:57 by upolat            #+#    #+#             */
/*   Updated: 2024/11/23 01:35:35 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0) {}

ClapTrap::ClapTrap(const ClapTrap &other)
    : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints),
    _attackDamage(other._attackDamage) {}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {}

void ClapTrap::attack(const std::string& target) {
    (void)target;
}

void ClapTrap::takeDamage(unsigned int amount) {
    (void)amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    (void)amount;
}