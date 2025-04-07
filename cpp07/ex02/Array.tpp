/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:34:15 by upolat            #+#    #+#             */
/*   Updated: 2025/04/07 21:01:14 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <class T> Array<T>::Array() : _arr(nullptr), _size(0) {};

template <class T> Array<T>::Array(const Array &other) {
	_size = other._size;
	if (_size > 0) {
		_arr = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_arr[i] = other._arr[i];
	} else
		_arr = nullptr;
}

template <class T> Array<T>& Array<T>::operator=(const Array &other) {
	if (this != &other) {
		delete[] _arr;
		_size = other._size;
		if (_size > 0) {
			_arr = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
				_arr[i] = other._arr[i];
		} else
			_arr = nullptr;
	}
	return *this;
}

template <class T> Array<T>::~Array() {
	delete[] _arr;
}

template <class T> T &Array<T>::operator [] (unsigned int index) {
	if (index >= _size)
		throw(std::runtime_error("Index out of bounds"));
	return _arr[index];
}

template <class T> Array<T>::Array(unsigned int n) : _size(n) {
	if (_size > 0)
		_arr = new T[_size];
	else
		_arr = nullptr;
}

template <class T> unsigned int Array<T>::size() const {
	return _size;
}
