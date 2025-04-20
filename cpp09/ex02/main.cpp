/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:12:49 by upolat            #+#    #+#             */
/*   Updated: 2025/04/20 03:04:36 by upolat           ###   ########.fr       */
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
		
		clock_t start = clock();
		pmm.mergeInsertSort(vec);
		double diff1 = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000000.0;

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
		
		start = clock();
		pmm.mergeInsertSort(dq);
		double diff2 = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000000.0;

		std::cout << "After for std::deque:    ";
		for (int i : dq)
			std::cout << i << " ";
		std::cout << std::endl;

		// Assert that the deque is indeed sorted
		for (size_t i = 1; i < dq.size(); i++)
			assert(dq[i] >= dq[i - 1]);

		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << std::fixed << diff1 << std::endl; 
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque  : " << std::fixed << diff2 << std::endl; 
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}