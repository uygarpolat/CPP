/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:12:11 by upolat            #+#    #+#             */
/*   Updated: 2025/04/18 02:13:59 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <deque>
#include <stdexcept>
#include <utility> // for std::pair
#include <iostream>
#include <iterator>
#include <algorithm>

class PmergeMe {
	private:
		std::vector<int>	_containerVector;
		std::deque<int>		_containerDeque;
		int					_recursionDepth;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		PmergeMe(int argc, char **argv);

		std::vector<int> getContainerVector();
		std::deque<int> getContainerDeque();

		// template <class T>
		// void insertLosers(T& winners, T& losers) {
		// 	return;
		// }
		
		// template <class T>
		// void mergeInsertSortPairs(std::vector<std::pair<int, int>> pairs) {
				
		// 	size_t size = pairs.size();
			
		// 	if (size < 2)
		// 		return;
			
		// 	// if size of pairs is 1, sort the pair by the bigger element which is in second position
		// 	if (size == 2 && pairs[0].second > pairs[1].second) {
		// 		std::swap(pairs[0], pairs[1]);
		// 		return;
		// 	}
			
	
		// 	T leftover;		
			
		// 	for (size_t i = 0; i < size; i += 2) {
		// 		if (i + 1 < size) {
		// 			if (pairs[i] > pairs[i+1])
		// 				pairs.push_back(std::make_pair(container[i], container[i+1]));
		// 			else
		// 				pairs.push_back(std::make_pair(container[i+1], container[i]));
		// 		}
		// 		else
		// 			leftover.push_back(container[i]);
		// 	}

		// 	mergeInsertSortPairs(pairs);

		// 	return;
		
			// // specialLoser is the loser that belonged to the pair with the smallest winner
			// int specialLoser = pairs[0].second;
		
			// T winners;
			// for (const auto &pr : pairs) {
			// 	winners.push_back(pr.first);
			// 	std::cout << "Pair: " << pr.first << "-" << pr.second << std::endl;
			// }

			// return;
		
			// insertionSortMerge(winners);
		
			// winners.insert(winners.begin(), specialLoser);
		
			// T losers;
			// // Skipping index 0, because we already added it as the specialLoser
			// for (size_t i = 1; i < pairs.size(); ++i)
			// 	losers.push_back(pairs[i].second);
			// if (leftover.size())
			// 	losers.push_back(leftover[0]);
			
			// insertLosers(winners, losers);
		
			// container = winners;
		// }

		// template <class T>
		// void mergeInsertSort(T &container) {
			
		// 	T leftover;
			
		// 	std::vector<std::pair<int, int>> pairs;

		// 	size_t size = container.size();
		
			
		// 	for (size_t i = 0; i < size; i += 2) {
		// 		if (i + 1 < size) {
		// 			if (container[i] > container[i+1])
		// 				pairs.push_back(std::make_pair(container[i], container[i+1]));
		// 			else
		// 				pairs.push_back(std::make_pair(container[i+1], container[i]));
		// 		}
		// 		else
		// 			leftover.push_back(container[i]);
		// 	}

		// 	mergeInsertSortPairs(pairs);

		// 	// Print pairs
		// 	std::cout << "Pairs after sorting: ";
		// 	for (const auto &pr : pairs) {
		// 		std::cout << pr.first << "-" << pr.second << " ";
		// 	}
		// 	std::cout << std::endl;
		// }

		template<class Container>
		void moveRange(Container& dst,
						Container& src,
						typename Container::size_type i,
						typename Container::size_type n,
						typename Container::size_type j)
		{
		
			// clamp i and n so we stay in-bounds of src
			if (i > src.size()) i = src.size();
			n = std::min(n, src.size() - i);
		
			// clamp j so we stay in-bounds of dst
			if (j > dst.size()) j = dst.size();
		
			// locate our iterators
			auto first      = std::next(src.begin(),       i);
			auto last       = std::next(first,             n);
			auto insert_pos = std::next(dst.begin(),       j);
		
			// 1) move‑insert [first,last) into dst at insert_pos
			dst.insert(insert_pos,
					   std::make_move_iterator(first),
					   std::make_move_iterator(last));
		
			// 2) erase that same range from src
			src.erase(first, last);
		}
		

		template <class T>
		void insertPend(T& main, T& pend, int level) {
			if (!pend.size())
				return;
			(void)main;
			(void)level;
		}
		
		template <class T>
		void mergeInsertSort(T &container) {
			
			pairSort(container, 1);

			std::cout << "Container after pairSort: ";
			for (auto v : container)
				std::cout << v << "-";
			std::cout << std::endl;
			
			createMainAndPend(container, _recursionDepth);
		}

		template <class T>
		void createMainAndPend(T &container, int level) {

			if (level == 0)
				return;
			
			T main;
			T pend;
			T leftover;
			
			size_t containerSize = container.size();
			size_t elementSize  = 1 << (level - 1); // This is equal to 2^(level - 1)

			int alternator = 0;
			moveRange(main, container, 0, elementSize, containerSize);

			while (container.size() > elementSize) {
				if (alternator % 2 == 0)
					moveRange(main, container, 0, elementSize, main.size());
				else if (alternator % 2 == 1)
					moveRange(pend, container, 0, elementSize, pend.size());	
				alternator++;
			}

			moveRange(leftover, container, 0, container.size(), leftover.size());

			insertPend(main, pend, level);

			moveRange(container, main, 0, main.size(), container.size());
			moveRange(container, leftover, 0, leftover.size(), container.size());

			
			
			std::cout << "Level: " << level << std::endl;
			std::cout << "Main: ";
			for (auto v : main)
				std::cout << v << "-";
			std::cout << std::endl;
			std::cout << "Pend: ";
			for (auto v : pend)
				std::cout << v << "-";
			std::cout << std::endl;
			std::cout << "Leftover: ";
			for (auto v : leftover)
				std::cout << v << "-";
			std::cout << std::endl;
			std::cout << "Container after createMainAndPend: ";
			for (auto v : container)
				std::cout << v << "-";
			std::cout << std::endl;
			std::cout << "--------------------------" << std::endl;
			createMainAndPend(container, level - 1);
	
		}
	
		template <class T>
		void pairSort(T &container, int level) {
			
			size_t initial = (1 << (level - 1)) - 1;
			size_t offset  = 1 << (level - 1);
			size_t size = container.size();

			if (initial + offset >= size)
				return;
			
			_recursionDepth = level;

			for (size_t i = initial; i < size; i += (pow(2, level))) {
				if (i + offset < size) {
					if (container[i] > container[i + offset]) {
						std::swap_ranges(container.begin() + i - initial,
										container.begin() + i - initial + offset,
										container.begin() + i - initial + offset);
					}
				}
				else
					break;
			}
			pairSort(container, level + 1);
		}

	
};