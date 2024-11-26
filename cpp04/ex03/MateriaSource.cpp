/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:17:45 by upolat            #+#    #+#             */
/*   Updated: 2024/11/26 19:16:44 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i)
        _catalogue[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    for (int i = 0; i < 4; ++i) {
        if (other._catalogue[i])
            _catalogue[i] = other._catalogue[i]->clone();
        else
            _catalogue[i] = nullptr;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete _catalogue[i];
            if (other._catalogue[i])
                _catalogue[i] = other._catalogue[i]->clone();
            else
                _catalogue[i] = nullptr;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        delete _catalogue[i];
        _catalogue[i] = nullptr;
    }
}

void MateriaSource::learnMateria(AMateria *m) {
    if (!m)
        return ;
    for (int i = 0; i < 4; i++) {
        if (!_catalogue[i]) {
            _catalogue[i] = m;
            break ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (_catalogue[i] && _catalogue[i]->getType() == type)
            return _catalogue[i]->clone();
    }
    return nullptr;
}
