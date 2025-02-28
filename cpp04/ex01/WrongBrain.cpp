/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongBrain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:17:49 by upolat            #+#    #+#             */
/*   Updated: 2024/11/25 16:19:53 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongBrain.hpp"
#include <iostream>

WrongBrain::WrongBrain() : _ideaCounter(0) {
        std::cout << "Default Constructor called for WrongBrain" << std::endl;
}

WrongBrain::WrongBrain(const WrongBrain &other) {
        std::cout << "Copy constructor called for WrongBrain" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
}

WrongBrain &WrongBrain::operator=(const WrongBrain &other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            ideas[i] = other.ideas[i];
        }
        _ideaCounter = other._ideaCounter;
    }
    std::cout << "Copy assignment operator constructor called for WrongBrain" << std::endl;
    return *this;
}

WrongBrain::~WrongBrain() {
        std::cout << "Destructor called for WrongBrain" << std::endl;
}

void WrongBrain::setIdea(std::string const &ideaString) {
    if (_ideaCounter < 100)
        ideas[_ideaCounter++] = ideaString;
    else
        std::cout << "This WrongBrain cannot hold that many ideas!" << std::endl;
}
        
        
void WrongBrain::getIdea(const unsigned int ideaNumber) const {
    if (ideaNumber < _ideaCounter)
        std::cout << ideas[ideaNumber] << std::endl;
    else
        std::cout << "This WrongBrain cannot retrieve that idea!" << std::endl;
}

void WrongBrain::getIdeas() const {
    if (!_ideaCounter) {
        std::cout << "I don't have any ideas yet!" << std::endl;
        return ;
    }
    std::cout << "Here are all " << _ideaCounter << " of my thoughts:" << std::endl;
    for (unsigned int i = 0; i < _ideaCounter; i++)
        std::cout << ideas[i] << std::endl;
}