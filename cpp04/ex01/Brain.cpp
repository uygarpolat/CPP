/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:17:49 by upolat            #+#    #+#             */
/*   Updated: 2024/11/24 21:33:42 by upolat           ###   ########.fr       */
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
}

Brain &Brain::operator=(const Brain &other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            ideas[i] = other.ideas[i];
        }
    }
    std::cout << "Copy assignment operator constructor called for Brain" << std::endl;
    return *this;
}

Brain::~Brain() {
        std::cout << "Destructor called for Brain" << std::endl;
}

void Brain::setIdeas(std::string &ideaString) {
    if (_ideaCounter < 100)
        ideas[_ideaCounter++] = ideaString;
    else
        std::cout << "This brain cannot hold that many ideas!" << std::endl;
}
        
        
std::string Brain::getIdeas(const int ideaNumber) {
    if (_ideaCounter < 100)
        return ideas[ideaNumber];
    else {
        std::cout << "This brain cannot hold that many ideas!" << std::endl;
        return nullptr;
    }
}