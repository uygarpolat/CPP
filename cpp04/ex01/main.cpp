/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:38:10 by upolat            #+#    #+#             */
/*   Updated: 2024/11/24 20:36:42 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

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

    for (int i = 0; i < size; i++)
		delete animalArray[i];
    delete[] animalArray;

    return 0;
}