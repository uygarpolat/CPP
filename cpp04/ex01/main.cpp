/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:38:10 by upolat            #+#    #+#             */
/*   Updated: 2024/11/25 17:59:39 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    int size = 4;
	Animal	**animalArray = new Animal*[size];

    for (int i = 0; i < size; i++) {
        if (i < size / 2)
            animalArray[i] = new Dog();
        else
            animalArray[i] = new Cat();
    }

    for (int i = 0; i < size; i++) {
        animalArray[i]->makeSound();
    }

    for (int i = 0; i < size; i++)
		delete animalArray[i];
    delete[] animalArray;

    Cat *cat = new Cat();

    cat->setIdea("I can think??");
    cat->setIdea("I can think!!");
    cat->setIdea("I *can* think??");
    cat->setIdea("*I* can think!!");
    cat->getIdea(0);
    cat->getIdea(1);
    cat->getIdea(2);
    cat->getIdea(3);
    cat->getIdea(4); // This will not be able to find that particular idea.
    std::cout << "Ideas of the cat coming in bulk:" << std::endl;
    cat->getIdeas();

   Dog *dog = new Dog();

    dog->setIdea("Woof");
    dog->setIdea("Wooooof");
    dog->setIdea("Wooooooooof");
    dog->setIdea("Wooooooooooooooof");
    dog->setIdea("Woooooooooooooooooooof");
    dog->getIdea(0);
    dog->getIdea(1);
    dog->getIdea(2);
    dog->getIdea(3);
    dog->getIdea(4);
    dog->getIdea(5); // This will not be able to find that particular idea.
    std::cout << "Ideas of the dog coming in bulk:" << std::endl;
    dog->getIdeas();
    
    std::cout << "xxxxxxxx Now testing if copy assignment operator deep copies for Cat and Dog classes xxxxxxxxxxx" << std::endl;
    
    // Copying dog to dog2, cat to cat2;
    Dog *dog2 = new Dog();
    *dog2 = *dog;
    Cat *cat2 = new Cat();
    *cat2 = *cat;
    
    // Deleting cat and dog;
    delete dog;
    delete cat;
    
    // Trying to get ideas of cat2 and dog2.
    // If deep copy is successful, it should print out the same ideas as cat and dog, even though they are deleted.
    cat2->getIdeas();
    dog2->getIdeas();
    
    delete cat2;
    delete dog2;

    // Now testing the deep copy of copy constructor:

    Dog *dog3 = new Dog();
    dog3->setIdea("Bark");
    dog3->setIdea("Baaaaark");

    // Copying dog3 into dog4 using copy contructor
    Dog *dog4 = new Dog(*dog3);
    // Delete original dog
    dog3->getIdeas();
    delete dog3;
    std::cout << "--------------If deep copy is succesful, the line below should list the 2 ideas of dog4 ----------------" << std::endl;
    dog4->getIdeas();

    delete dog4;


    //Now let's contast that with WrongCat class, who purposefully uses a shallow copy and "has a" WrongBrain
    std::cout << "++++++++++ Starting shallow copy demonstration with two wrongCat objects with wrongBrain +++++++++++" << std::endl;

    WrongCat *wrongCat1 = new WrongCat();
    WrongCat *wrongCat2 = new WrongCat();
    
    wrongCat1->setIdea("I only have one idea...");
    *wrongCat2 = *wrongCat1;
    wrongCat2->setIdea("I also only have one idea...");
    std::cout << "********** If the copy is shallow (which is the intention), WrongCat2 must have 2 ideas below instead of 1 **********" << std::endl;
    wrongCat2->getIdeas();

    delete wrongCat1;
    delete wrongCat2;
    return 0;
}