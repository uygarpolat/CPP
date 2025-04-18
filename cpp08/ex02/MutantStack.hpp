/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:04:36 by upolat            #+#    #+#             */
/*   Updated: 2025/04/18 23:01:06 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:

		MutantStack() = default;
		MutantStack(const MutantStack &other) = default;
		MutantStack &operator=(const MutantStack &other) = default;
		~MutantStack() = default;
		
		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator        begin();
		iterator        end();
		const_iterator  begin() const;
		const_iterator  end() const;
		const_iterator  cbegin() const;
		const_iterator  cend() const;

		reverse_iterator        rbegin();
		reverse_iterator        rend();
		const_reverse_iterator  rbegin() const;
		const_reverse_iterator  rend() const;
		const_reverse_iterator  crbegin() const;
		const_reverse_iterator  crend() const;
};

#include "MutantStack.tpp"
