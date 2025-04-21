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

long long Span::shortestSpan() {
	if (_data.size() < 2)
		throw std::runtime_error("Error: Not enough elements to find a span");

	std::vector<int> sorted = _data;
	std::sort(sorted.begin(), sorted.end());

	long long minSpan = static_cast<long long>(std::numeric_limits<long long>::max());

	for (size_t i = 1; i < sorted.size(); i++) {
		long long diff = static_cast<long long>(sorted[i]) - static_cast<long long>(sorted[i - 1]);
		if (diff < minSpan)
			minSpan = diff;
	}

	return minSpan;
}

long long Span::longestSpan() {
	if (_data.size() < 2)
		throw std::runtime_error("Error: Not enough elements to find a span");

	int max = *std::max_element(_data.begin(), _data.end());
	int min = *std::min_element(_data.begin(), _data.end());
	return static_cast<long long >(max) - static_cast<long long>(min);
}

void	Span::addNumbers(std::vector<int>& newData) {
	if (newData.size() + _data.size() > _N)
		throw std::runtime_error("Error: Attempting to overflow the container");
	else
		_data.insert(_data.end(), newData.begin(), newData.end());
}

void Span::printContainer() const {
	std::cout << YELLOW << "Container: " << DEFAULT;
	for (size_t i = 0; i < _data.size(); i++) {
		std::cout << _data[i];
		if (i != _data.size() - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}