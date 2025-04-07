/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:48:21 by upolat            #+#    #+#             */
/*   Updated: 2025/04/07 11:18:06 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "D.hpp"

int main(void) {

	std::srand(time(NULL));
	
	std::cout << GREEN << "Identify pointers:" << DEFAULT << std::endl;
	
	Base* test1 = generate();
	Base* test2 = generate();
	Base* test3 = generate();
	Base* test4 = new A();
	Base* test5 = new B();
	Base* test6 = new C();
	Base* test7 = new D();

	identify(test1);
	identify(test2);
	identify(test3);
	identify(test4);
	identify(test5);
	identify(test6);
	identify(test7);

	delete test1;
	delete test2;
	delete test3;
	delete test4;
	delete test5;
	delete test6;
	delete test7;

	std::cout << GREEN << "Identify references:" << DEFAULT << std::endl;
	
	A test_ref1;
	B test_ref2;
	C test_ref3;
	D test_ref4;

	identify(test_ref1);
	identify(test_ref2);
	identify(test_ref3);
	identify(test_ref4);

	Base *nullTest = nullptr;
	identify(nullTest);

	return 0;
}