/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:55:52 by upolat            #+#    #+#             */
/*   Updated: 2024/11/23 22:11:56 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("Unknown name", 100, 50, 20) {
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name, 100, 50, 20) {
    std::cout << "ScavTrap parametrized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "Destructor is called for ScavTrap " << _name << std::endl;
}


void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    std::cout << "ScavTrap " << _name
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