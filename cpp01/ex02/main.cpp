/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:53:00 by upolat            #+#    #+#             */
/*   Updated: 2024/11/20 14:42:52 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main (void) {

    /*Write a program that contains:
    • A string variable initialized to "HI THIS IS BRAIN".
    • stringPTR: A pointer to the string.
    • stringREF: A reference to the string.*/

    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;
    /*
    Your program has to print:
    • The memory address of the string variable.
    • The memory address held by stringPTR.
    • The memory address held by stringREF.
    And then:
    • The value of the string variable.
    • The value pointed to by stringPTR.
    • The value pointed to by stringREF
    */
   std::cout << "The memory address of the string variable: " << &string << std::endl;
   std::cout << "he memory address held by stringPTR: " << stringPTR << std::endl;
   std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
   std::cout << std::endl;
   std::cout << "The value of the string variable: " << string << std::endl;
   std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
   std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}
