/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:39:14 by upolat            #+#    #+#             */
/*   Updated: 2025/04/21 23:58:46 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	{	
		std::cout << "--- MutantStack ---" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	{
		std::cout << "--- List ---" << std::endl;
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		// [...]
		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int, std::list<int> > s(lst);
	}

	{
        std::cout << "--- Reverse iteration on MutantStack ---" << std::endl;
        MutantStack<int> revStack;
        revStack.push(10);
        revStack.push(20);
        revStack.push(30);
        revStack.push(40);

        std::cout << "Should print: 40, 30, 20, 10" << std::endl;
        for (MutantStack<int>::reverse_iterator rit = revStack.rbegin(); rit != revStack.rend(); rit++)
            std::cout << *rit << std::endl;
    }

    {
        std::cout << "--- Const iteration on MutantStack ---" << std::endl;
        MutantStack<int> original;
        original.push(7);
        original.push(14);
        original.push(21);

        const MutantStack<int> constStack = original;
        std::cout << "Should print: 7, 14, 21" << std::endl;
        for (MutantStack<int>::const_iterator cit = constStack.cbegin(); cit != constStack.cend(); ++cit)
            std::cout << *cit << std::endl;
			
		// Try modifying an element in the const stack (should not compile)
		MutantStack<int>::const_iterator cit2 = constStack.cbegin();
		//*cit2 = 42; // Uncommenting this line should cause a compilation error
		(void)cit2; // To avoid unused variable warning
	}
	

	{
		std::cout << "--- Empty MutantStack ---" << std::endl;
		MutantStack<int> emptyStack;
		std::cout << "Should print: 0" << std::endl;
		std::cout << emptyStack.size() << std::endl;
	}

	{
		std::cout << "--- Copy constructor and assignment operator ---" << std::endl;
		MutantStack<int> original;
		original.push(1);
		original.push(2);
		original.push(3);
		std::cout << "Original stack size: " << original.size() << std::endl;

		MutantStack<int> copy(original); // Copy constructor
		std::cout << "Copy stack size: " << copy.size() << std::endl;

		MutantStack<int> assigned;
		assigned = original; // Assignment operator
		std::cout << "Assigned stack size: " << assigned.size() << std::endl;
    }

	return 0;
}