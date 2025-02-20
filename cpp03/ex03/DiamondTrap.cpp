/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:37:21 by upolat            #+#    #+#             */
/*   Updated: 2025/02/20 14:30:23 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("UnknownName_clap_name", 100, 50, 30) {
    _name = "UnknownName";
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name", 100, 50, 30) {
    std::cout << "DiamondTrap parametrized constructor called" << std::endl;
    _name = name;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
    std::cout << "DiamondTrap copy constructor called for " << _name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        _name = other._name; 
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "Destructor is called for DiamondTrap " << DiamondTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
    std::cout << "My DiamondTrap name is " << DiamondTrap::_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}