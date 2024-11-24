/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:38:10 by upolat            #+#    #+#             */
/*   Updated: 2024/11/24 16:51:25 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void) {
 

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    std::cout << "The line above should read: Cat says MEOW" << std::endl;
    j->makeSound();
    std::cout << "The line above should read: Dog says BARK" << std::endl;
    meta->makeSound();
    std::cout << "The line above should read: Animal makes random animal noises" << std::endl;

    delete meta;
    delete j;
    delete i;

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    wrongAnimal->makeSound(); // Will output the animal sound, which is correct.
    std::cout << "The line above should read: WrongAnimal makes random animal noises" << std::endl;
    wrongCat->makeSound(); // Will output the animal sound, which is incorrect.
    std::cout << "The line above should read: WrongCat makes random animal noises" << std::endl;

    delete wrongAnimal;
    delete wrongCat;
    
    return 0;
}