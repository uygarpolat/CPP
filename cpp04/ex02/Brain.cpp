/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:17:49 by upolat            #+#    #+#             */
/*   Updated: 2025/02/28 13:11:42 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() : _ideaCounter(0) {
        std::cout << "Default Constructor called for Brain" << std::endl;
}

Brain::Brain(const Brain &other) {
        std::cout << "Copy constructor called for Brain" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
    _ideaCounter = other._ideaCounter;
}

Brain &Brain::operator=(const Brain &other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            ideas[i] = other.ideas[i];
        }
        _ideaCounter = other._ideaCounter;
    }
    std::cout << "Copy assignment operator constructor called for Brain" << std::endl;
    return *this;
}

Brain::~Brain() {
        std::cout << "Destructor called for Brain" << std::endl;
}

void Brain::setIdea(std::string const &ideaString) {
    if (_ideaCounter < 100)
        ideas[_ideaCounter++] = ideaString;
    else
        std::cout << "This brain cannot hold that many ideas!" << std::endl;
}
        
        
void Brain::getIdea(const unsigned int ideaNumber) const {
    if (ideaNumber < _ideaCounter)
        std::cout << ideas[ideaNumber] << std::endl;
    else
        std::cout << "This brain cannot retrieve that idea!" << std::endl;
}

void Brain::getIdeas() const {
    if (!_ideaCounter) {
        std::cout << "I don't have any ideas yet!" << std::endl;
        return ;
    }
    std::cout << "Here are all " << _ideaCounter << " of my thoughts:" << std::endl;
    for (unsigned int i = 0; i < _ideaCounter; i++)
        std::cout << ideas[i] << std::endl;
}