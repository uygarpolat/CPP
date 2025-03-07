/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:34:15 by upolat            #+#    #+#             */
/*   Updated: 2025/03/06 22:11:06 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T> Array<T>::Array() _arr(0), _size(0) {};
Array::Array(size_t n) {
	
}

template <typename T> class Array {
	private:
		T*		_arr;
		size_t	_size;
	public:
		Array();
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		Array(size_t n);
};
