/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:37:18 by upolat            #+#    #+#             */
/*   Updated: 2025/02/28 12:53:53 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    _type = "Dog";
    std::cout << "Default Constructor called for " << getType() << std::endl;
    _brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
    _brain = new Brain(*(other._brain));
    std::cout << "Copy constructor called for " << getType() << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        _type = other.getType();
	    delete _brain;
	    _brain = new Brain();
	    *_brain = *(other._brain);
    }
    std::cout << "Copy assignment operator constructor called for " << getType() << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "Destructor called for Dog" << std::endl;
    delete _brain;
}

void Dog::makeSound(void) const {
    std::cout << getType() << " says BARK" << std::endl;
}

void Dog::getIdea(const unsigned int ideaNumber) const {
	_brain->getIdea(ideaNumber);
}

void Dog::getIdeas(void) const {
	_brain->getIdeas();
}

void Dog::setIdea(std::string idea) {
	_brain->setIdea(idea);
}