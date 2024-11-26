/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:58:02 by upolat            #+#    #+#             */
/*   Updated: 2024/11/27 00:12:34 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main() {
    // Subject-provided tests
    std::cout << "Tests from the subject:" << std::endl;

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob); // Use ice on bob
    me->use(1, *bob); // Use cure on bob

    delete bob;
    delete me;
    delete src;

    std::cout << std::endl << "Additional custom tests:" << std::endl;

    // Custom tests start here
    // 1. Create a new MateriaSource and learn more Materias
    std::cout << "Creating a new MateriaSource and learning Ice and Cure again:" << std::endl;
    IMateriaSource* my_src = new MateriaSource();
    my_src->learnMateria(new Ice());
    my_src->learnMateria(new Cure());

    // 2. Create characters and equip multiple Materias
    Character* hero = new Character("Hero");
    Character* villain = new Character("Villain");

    AMateria* ice1 = my_src->createMateria("ice");
    AMateria* ice2 = my_src->createMateria("ice");
    AMateria* cure1 = my_src->createMateria("cure");
    AMateria* cure2 = my_src->createMateria("cure");

    hero->equip(ice1);
    hero->equip(cure1);
    villain->equip(ice2);
    villain->equip(cure2);

    // 3. Use equipped Materias
    std::cout << "Hero uses Ice and Cure on Villain:" << std::endl;
    hero->use(0, *villain);
    hero->use(1, *villain);

    std::cout << "Villain uses Ice and Cure on Hero:" << std::endl;
    villain->use(0, *hero);
    villain->use(1, *hero);

    // 5. Copy Assignment Operator Test
    std::cout << "Testing deep copy via copy assignment operator:" << std::endl;
    *villain = *hero; // Deep copy hero's inventory into villain
    std::cout << "Villain uses Hero's Materia (deep copy):" << std::endl;
    villain->use(0, *hero); // Villain should use Hero's Ice Materia
    villain->use(1, *hero); // Villain should use Hero's Cure Materia

    // 6. Verify deep copy
    std::cout << "Deleting Hero and ensuring Villain still has independent Materia:" << std::endl;
    delete hero;

    // Verify Villain still works independently
    std::cout << "Using Villain's independent Materia after Hero deletion:" << std::endl;
    villain->use(0, *villain); // Villain's Ice Materia
    villain->use(1, *villain); // Villain's Cure Materia

    // Cleanup
    delete villain;
    delete my_src;

    return 0;
}