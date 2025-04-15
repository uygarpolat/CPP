/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:12:11 by upolat            #+#    #+#             */
/*   Updated: 2025/04/15 10:04:35 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <deque>
#include <algorithm> // for std::sort
#include <stdexcept>
#include <utility> // for std::pair
#include <iostream>

class PmergeMe {
	private:
		std::vector<int> _containerVector;
		std::deque<int> _containerDeque;
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

		template <class T>
		void insertionSortMerge(T &container) {

			T leftover;
				
			if (container.size() < 2)
				return;
	
			std::vector<std::pair<int, int>> pairs;
		
			size_t size = container.size();
			
			for (size_t i = 0; i < size; i += 2) {
				if (i + 1 < size) {
					if (container[i] > container[i+1])
						pairs.push_back(std::make_pair(container[i], container[i+1]));
					else
						pairs.push_back(std::make_pair(container[i+1], container[i]));
				}
				else
					leftover.push_back(container[i]);
					// pairs.push_back(std::make_pair(container[i], container[i]));
			}
		
			// This sorts pairs by the first element of each pair in ascending order.
			// The first elements will then comprise the winners container later on.
			std::sort(pairs.begin(), pairs.end(),
				[](const std::pair<int, int>& a,
					const std::pair<int, int>& b) {
					return a.first < b.first;
				});
		
		
			// specialLoser is the loser that belonged to the pair with the smallest winner
			int specialLoser = pairs[0].second;
		
			T winners;
			for (const auto &pr : pairs) {
				winners.push_back(pr.first);
				std::cout << "Pair: " << pr.first << "-" << pr.second << std::endl;
			}

			return;
		
			insertionSortMerge(winners);
		
			winners.insert(winners.begin(), specialLoser);
		
			T losers;
			// Skipping index 0, because we already added it as the specialLoser
			for (size_t i = 1; i < pairs.size(); ++i)
				losers.push_back(pairs[i].second);
			if (leftover.size())
				losers.push_back(leftover[0]);
			
			//insertLosers(winners, losers);
		
			container = winners;
		}		
		
		// 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7
		template <class T>
		void pairSort(T &container, int level) {
			
		}
};