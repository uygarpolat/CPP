/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:12:49 by upolat            #+#    #+#             */
/*   Updated: 2025/04/20 03:13:42 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {

	if (argc < 2)
		return 1;
	try {
		PmergeMe pmm(argc, argv);

		std::vector<int> vec = pmm.getContainerVector();
		std::deque<int> dq = pmm.getContainerDeque();
		
		pmm.comparisons = 0;

		std::cout << "Before for std::vector: ";
		for (int i : vec)
			std::cout << i << " ";
		std::cout << std::endl;
		
		auto t0 = std::chrono::high_resolution_clock::now();
		pmm.mergeInsertSort(vec);
		auto t1 = std::chrono::high_resolution_clock::now();

		std::cout << "After for std::vector:   ";
		for (int i : vec)
			std::cout << i << " ";
		std::cout << std::endl;

		// Assert that the vector is indeed sorted
		for (size_t i = 1; i < vec.size(); i++)
			assert(vec[i] >= vec[i - 1]);
		
		pmm.comparisons = 0;
		std::cout << "Before for std::deque:  ";
		for (int i : dq)
			std::cout << i << " ";
		std::cout << std::endl;
		
		auto t2 = std::chrono::high_resolution_clock::now();
		pmm.mergeInsertSort(dq);
		auto t3 = std::chrono::high_resolution_clock::now();

		std::cout << "After for std::deque:    ";
		for (int i : dq)
			std::cout << i << " ";
		std::cout << std::endl;

		// Assert that the deque is indeed sorted
		for (size_t i = 1; i < dq.size(); i++)
			assert(dq[i] >= dq[i - 1]);

		std::chrono::duration<double, std::micro> us0 = t1 - t0;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << std::fixed << std::setprecision(3) << us0.count() << " µs\n";

		std::chrono::duration<double, std::micro> us1 = t3 - t2;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque  : " << std::fixed << std::setprecision(3) << us1.count() << " µs\n";
		
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}