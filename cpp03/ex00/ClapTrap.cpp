/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:15:57 by upolat            #+#    #+#             */
/*   Updated: 2024/11/23 16:51:14 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap() : _name("Unknown name"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default constructor is called for ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints),
    _attackDamage(other._attackDamage) {
     std::cout << "Copy constructor called" << std::endl;
     }

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor is called for " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
        std::cout << "Parametrized constructor is called for " << _name << std::endl;
    }

void ClapTrap::attack(const std::string& target) {
    std::cout << "ClapTrap " << _name
                << " attacks " << target;
    if (!_hitPoints)
        std::cout << ", alas it doesn't have Hit Points, so nothing happens!" << std::endl;
    else if (!_energyPoints)
        std::cout << ", alas it doesn't have Energy Points, so nothing happens!" << std::endl;
    else
    {
        std::cout << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
        // other.takeDamage(_attackDamage);
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (!_hitPoints || !_energyPoints) {
        std::cout << "ClapTrap " << _name << " cannot take any more damage!" << std::endl;
        _hitPoints -= amount;
        if (_hitPoints < 0)
            _hitPoints = 0;
    }
    else {
        _hitPoints -= amount;
        if (_hitPoints < 0)
            _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount << " damage, now it has " << _hitPoints << " Hit Points!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    std::cout << "ClapTrap " << _name
                << " tries healing itself";
    if (!_hitPoints)
        std::cout << ", alas it doesn't have Hit Points, so nothing happens!" << std::endl;
    else if (!_energyPoints)
        std::cout << ", alas it doesn't have Energy Points, so nothing happens!" << std::endl;
    else
    {
        std::cout << ", and succeeds! It got " << amount << " Hit Points back";
        _energyPoints--;
        _hitPoints += amount;
        std::cout << ", now it has " << _hitPoints << std::endl;;
    }
}