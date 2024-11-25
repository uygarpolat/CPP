/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:38:10 by upolat            #+#    #+#             */
/*   Updated: 2024/11/25 18:48:52 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    // This is fine because we are creating an instance of Cat.
    Cat *cat = new Cat();
    cat->setIdea("I can think??");
    cat->getIdeas();
    delete cat;

    // This is also fine because we are creating an instance of Dog, even
    // though the pointer itself is of Animal. This is possible due to polymorphism.
    Animal* animal = new Dog();
    animal->makeSound();
    delete animal;

    /* The following would give a compile error, because Animal is an abstract class and
    cannot be instantiated. */
    //Animal* animal2 = new Animal();
    //animal2->makeSound();
    //delete animal2;

    // The following would also give a compile error due to same reason.
    //Animal animal3;
    //animal3.makeSound();
    
    return 0;
}