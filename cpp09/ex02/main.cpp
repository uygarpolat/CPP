/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:12:49 by upolat            #+#    #+#             */
/*   Updated: 2025/04/14 00:50:01 by upolat           ###   ########.fr       */
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
		
		clock_t start = clock();
		pmm.insertionSortMerge(vec);
		double diff1 = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000000.0;
		
		std::cout << "------------" << std::endl;
		
		start = clock();
		pmm.insertionSortMerge(dq);
		double diff2 = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000000.0;

		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << std::fixed << diff1 << std::endl; 
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << std::fixed << diff2 << std::endl; 
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}