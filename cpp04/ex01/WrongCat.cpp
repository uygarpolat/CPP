/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:20:28 by upolat            #+#    #+#             */
/*   Updated: 2024/11/25 17:26:06 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongBrain.hpp"

WrongCat::WrongCat() {
    _type = "WrongCat";
    std::cout << "Default Constructor called for " << getType() << std::endl;
    _wrongBrain = new WrongBrain();
}

WrongCat::WrongCat(const WrongCat &other) {
    _type = other.getType();
    std::cout << "Copy constructor called for " << getType() << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    if (this != &other) {
        _type = other.getType();
	    delete _wrongBrain;
	    _wrongBrain = new WrongBrain();
	    *_wrongBrain = *(other._wrongBrain);
    }
    std::cout << "Copy assignment operator constructor called for " << getType() << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "Destructor called for WrongCat" << std::endl;
    delete _wrongBrain;

}

void WrongCat::makeSound(void) const {
    std::cout << getType() << " says MEOW" << std::endl;
}

void WrongCat::getIdea(const unsigned int ideaNumber) const {
	_wrongBrain->getIdea(ideaNumber);
}

void WrongCat::getIdeas(void) const {
	_wrongBrain->getIdeas();
}

void WrongCat::setIdea(std::string idea) {
	_wrongBrain->setIdea(idea);
}