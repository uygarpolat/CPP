/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:55:25 by upolat            #+#    #+#             */
/*   Updated: 2024/11/27 00:14:55 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() : _name("Unknown") {
    for (int i = 0; i < 4; ++i)
        _slot[i] = nullptr;
}

Character::Character(std::string name) : _name(name) {
    for (int i = 0; i < 4; ++i)
        _slot[i] = nullptr;
}

Character::Character(const Character &other) : _name(other._name) {
    for (int i = 0; i < 4; ++i) {
        if (other._slot[i])
            _slot[i] = other._slot[i]->clone();
        else
            _slot[i] = nullptr;
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete _slot[i];
            _slot[i] = nullptr;
        }

        for (int i = 0; i < 4; ++i) {
            if (other._slot[i])
                _slot[i] = other._slot[i]->clone();
            else
                _slot[i] = nullptr;
        }
        _name = other._name;
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; ++i)
        delete _slot[i];
}

std::string const &Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m) {
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (_slot[i] == m)
            return;
    }
    for (int i = 0; i < 4; ++i) {
        if (!_slot[i]) {
            _slot[i] = m;
            return;
        }
    }
    std::cout << "Inventory full. Deleting extra Materia to avoid leaks." << std::endl;
    delete m;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4 || !_slot[idx])
        return;
    _slot[idx] = nullptr; // Nullify the slot, leave memory to the caller
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || !_slot[idx])
        return;
    _slot[idx]->use(target);
}