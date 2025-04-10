#include "Span.hpp"

Span::Span() : _N(0) {}
Span::Span(const Span &other) : _N(other._N), _data(other._data) {}
Span::~Span() {}
Span::Span(unsigned int N) : _N(N) {}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_data = other._data;
		_N = other._N;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (_data.size() < _N)
		_data.push_back(num);
	else
		throw std::runtime_error("Error: Attempting to overflow the container");
}

int Span::shortestSpan() {
	if (_data.size() < 2)
		throw std::runtime_error("Error: Not enough elements to find a span");
	std::sort(_data.begin(), _data.end());
	std::vector<int> adDif = _data;
	std::adjacent_difference(adDif.begin(), adDif.end(), adDif.begin());
	adDif.erase(adDif.begin());
	return	*std::min_element(adDif.begin() + 1, adDif.end());
}

int Span::longestSpan() {
	if (_data.size() < 2)
		throw std::runtime_error("Error: Not enough elements to find a span");
	return	*std::max_element(_data.begin(), _data.end()) -
			*std::min_element(_data.begin(), _data.end());
}

void	Span::addNumbers(std::vector<int> newData) {
	if (newData.size() + _data.size() > _N)
		throw std::runtime_error("Error: Attempting to overflow the container");
	else
		_data.assign(newData.begin(), newData.end());
}
