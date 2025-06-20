/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:12:49 by upolat            #+#    #+#             */
/*   Updated: 2025/04/22 23:42:10 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#define GREEN "\033[32m"
#define YELLOW "\033[93m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define DEFAULT "\033[0m"

int main(int argc, char **argv) {

	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <positive integers>" << std::endl;
		return 1;
	}
	try {
		PmergeMe pmm(argc, argv);

		std::vector<int> vec = pmm.getContainerVector();
		std::deque<int> dq = pmm.getContainerDeque();

		std::cout << RED << "======== Container 1 (std::vector) ========" << DEFAULT << std::endl;
		
		std::cout << YELLOW << "Before for std::vector: " << DEFAULT;
		for (int i : vec)
			std::cout << i << " ";
		std::cout << std::endl;
		
		auto t0 = std::chrono::high_resolution_clock::now();
		pmm.mergeInsertSort(vec);
		auto t1 = std::chrono::high_resolution_clock::now();

		std::cout << BLUE << "After for std::vector : " << DEFAULT;
		for (int i : vec)
			std::cout << i << " ";
		std::cout << std::endl;

		// Assert that the vector is indeed sorted
		for (size_t i = 1; i < vec.size(); i++)
			assert(vec[i] >= vec[i - 1]);
		
		std::cout << std::endl << RED << "======== Container 2 (std::deque) ========" << DEFAULT << std::endl;
		std::cout << YELLOW << "Before for std::deque : " << DEFAULT;
		for (int i : dq)
			std::cout << i << " ";
		std::cout << std::endl;
		
		auto t2 = std::chrono::high_resolution_clock::now();
		pmm.mergeInsertSort(dq);
		auto t3 = std::chrono::high_resolution_clock::now();

		std::cout << BLUE << "After for std::deque  : " << DEFAULT;
		for (int i : dq)
			std::cout << i << " ";
		std::cout << std::endl;

		// Assert that the deque is indeed sorted
		for (size_t i = 1; i < dq.size(); i++)
			assert(dq[i] >= dq[i - 1]);

		std::cout << std::endl << RED << "======== Sorting success report ========" << DEFAULT << std::endl;

		std::cout << GREEN << "\u2705 std::vector confirmed sorted" << DEFAULT << std::endl;
		std::cout << GREEN << "\u2705 std::deque  confirmed sorted" << DEFAULT << std::endl;

		std::cout << std::endl << RED << "======== Time report ========" << DEFAULT << std::endl;
		std::chrono::duration<double, std::micro> us0 = t1 - t0;
		std::cout << "Time to process a range of " << GREEN
					<< argc - 1 << DEFAULT << " elements with "
					<< YELLOW << "std::vector" DEFAULT << " : " << std::fixed << std::setprecision(3)
					<< GREEN << us0.count() << " µs" << DEFAULT << std::endl;

		std::chrono::duration<double, std::micro> us1 = t3 - t2;
		std::cout << "Time to process a range of " << GREEN
					<< argc - 1 << DEFAULT << " elements with "
					<< YELLOW << "std::deque" DEFAULT << "  : " << std::fixed << std::setprecision(3)
					<< GREEN << us1.count() << " µs" << DEFAULT << std::endl;
		std::cout << RED << "==============================" << DEFAULT << std::endl;
		
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}