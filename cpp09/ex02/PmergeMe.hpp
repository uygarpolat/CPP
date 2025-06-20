/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:12:11 by upolat            #+#    #+#             */
/*   Updated: 2025/04/27 00:10:39 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <assert.h>
#include <chrono>
#include <iomanip>

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

		template <class T>
		void mergeInsertSort(T &container) {
			pairSort(container, 1);
			createMainAndPend(container, _recursionDepth);
		}

		std::vector<int> getContainerVector();
		std::deque<int> getContainerDeque();
		
	private:

		uint64_t getJacobsthal(size_t n);

		template<typename Container>
		size_t binary_insert_by_group(	const Container& container,
										const Container& element,
										size_t elementSize)
		{
			
			int key = element[elementSize - 1];
			
			size_t lo = 0;
			size_t hi = container.size() / elementSize;
		
			while (lo < hi) {
				size_t mid = lo + (hi - lo) / 2;
				int midVal = container[mid * elementSize + elementSize - 1];
				if (midVal < key)
					lo = mid + 1;
				else
					hi = mid;				
			}
		
			return lo * elementSize;
		}

		template<class Container>
		void moveRange(Container& dst,
						Container& src,
						typename Container::size_type i,
						typename Container::size_type n,
						typename Container::size_type j)
		{
		
			if (i > src.size())
				i = src.size();
			n = std::min(n, src.size() - i);
		
			if (j > dst.size())
				j = dst.size();
		
			auto first      = std::next(src.begin(), i);
			auto last       = std::next(first, n);
			auto insert_pos = std::next(dst.begin(), j);
		
			dst.insert(insert_pos,
					   std::make_move_iterator(first),
					   std::make_move_iterator(last));
		
			src.erase(first, last);
		}
		

		template <class T>
		void insertPend(T& main, T& pend, int level) {
			if (!pend.size())
				return;
			size_t elementSize = 1 << (level - 1);
			size_t jacobsthalCount = 3;
			uint64_t repetition = getJacobsthal(jacobsthalCount - 2) * 2;
			T temp;
			
			while (pend.size()) {
				if (!repetition)
					repetition = getJacobsthal(jacobsthalCount - 2) * 2;

				if (repetition * elementSize > pend.size())
					repetition = pend.size() / elementSize;
				
				temp.clear();
				
				moveRange(temp, pend, elementSize * (repetition - 1), elementSize, temp.size());
				size_t insertPos = binary_insert_by_group(main, temp, elementSize); //
				moveRange(main, temp, 0, elementSize, insertPos);
				
				repetition--;
			}
		}
		
		template <class T>
		void createMainAndPend(T &container, int level) {

			if (level == 0)
				return;

			T main;
			T pend;
			T leftover;
			
			size_t containerSize = container.size();
			size_t elementSize  = 1 << (level - 1);

			int alternator = 0;
			moveRange(main, container, 0, elementSize, containerSize);

			while (container.size() >= elementSize) {
				if (alternator % 2 == 0)
					moveRange(main, container, 0, elementSize, main.size());
				else
					moveRange(pend, container, 0, elementSize, pend.size());	
				alternator++;
			}
			
			moveRange(leftover, container, 0, container.size(), leftover.size());

			insertPend(main, pend, level);

			moveRange(container, main, 0, main.size(), container.size());
			moveRange(container, leftover, 0, leftover.size(), container.size());
			
			createMainAndPend(container, level - 1);
	
		}
	
		template <class T>
		void pairSort(T &container, int level) {
			
			size_t initial = (1 << (level - 1)) - 1;
			size_t offset  = 1 << (level - 1);
			size_t size = container.size();

			if (initial + offset > size)
				return;
			
			_recursionDepth = level;

			for (size_t i = initial; i < size; i += (1u << level)) {
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
