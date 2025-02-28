/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:36:42 by upolat            #+#    #+#             */
/*   Updated: 2025/02/28 12:53:27 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    _type = "Cat";
    std::cout << "Default Constructor called for " << getType() << std::endl;
    _brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
    _brain = new Brain(*(other._brain));
    std::cout << "Copy constructor called for " << getType() << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        _type = other.getType();
	    delete _brain;
	    _brain = new Brain();
	    *_brain = *(other._brain);
    }
    std::cout << "Copy assignment operator constructor called for " << getType() << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "Destructor called for Cat" << std::endl;
    delete _brain;
}

void Cat::makeSound(void) const {
    std::cout << getType() << " says MEOW" << std::endl;
}

void Cat::getIdea(const unsigned int ideaNumber) const {
	_brain->getIdea(ideaNumber);
}

void Cat::getIdeas(void) const {
	_brain->getIdeas();
}

void Cat::setIdea(std::string idea) {
	_brain->setIdea(idea);
}