/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:19:02 by upolat            #+#    #+#             */
/*   Updated: 2024/11/23 23:27:25 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("Unknown name", 100, 30, 30) {
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name, 100, 30, 30) {
    std::cout << "FragTrap parametrized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "Destructor is called for FragTrap " << _name << std::endl;
}

void FragTrap::attack(const std::string& target) {
    std::cout << "FragTrap " << _name
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

void FragTrap::highFivesGuys(void) {
    if (_hitPoints || _energyPoints)
        std::cout << "FragTrap " << _name << " says: 'High five?'" << std::endl;
    else
        std::cout << "FragTrap " << _name << " cannot ask for a High Five..." << std::endl;
}