/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:11:25 by upolat            #+#    #+#             */
/*   Updated: 2025/03/05 17:26:17 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other) {
	(void)other;
}

Serializer &Serializer::operator=(const Serializer &other) {
	if (this != &other) {
		(void)other;
	}
	return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}
Data* Serializer::deserialize(uintptr_t raw) {
	Data *ptr = reinterpret_cast<Data*>(raw);
	return ptr;
}
