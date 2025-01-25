#include "Span.hpp"
#include <limits.h>

Span::Span(unsigned int N) : _container(0), _current_len(0), _max_len(N) {
	std::cout << "Span parameter constructor called" << std::endl;
};

Span::Span() :  _current_len(0), _max_len(0) {
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(const Span& other) :  _container(other._container), _current_len(other._current_len), _max_len(other._max_len) {
	std::cout << "Span copy constructor called" << std::endl;
}

Span::~Span() {
	std::cout << "Span destructor called" << std::endl;
}

Span&	Span::operator=(const Span& other) {
	std::cout << "Span copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	_container = other._container;
	_max_len =  other._max_len;
	_current_len = other._current_len;
	return (*this);
}

void	Span::addNumber(int value) {
	if (_current_len < _max_len) {
		_container.push_back(value);
		std::cout << value << " has been added" << std::endl;
		_current_len++;
	}
	else
		throw std::runtime_error("The limit of items has been reached");
}

long long	Span::shortestSpan() {
	if (_current_len <= 1)
		throw std::runtime_error("Cannot compute shortest shortest span: here are not enough elements.");

	long long smallestDiff = LONG_LONG_MAX;
	std::vector<int> temp_container(_container);
	std::sort(temp_container.begin(), temp_container.end());
	for (unsigned int i = 1; i < _current_len; i++) {
		if ((temp_container[i] - temp_container[i - 1]) < smallestDiff)
			smallestDiff = temp_container[i] - temp_container[i - 1];
	}
	return (smallestDiff);
}

long long	Span::longestSpan() {
	if (_current_len <= 1)
		throw std::runtime_error("Cannot compute longest span: here are not enough elements.");

	long long max = _container[0];
	long long min = _container[0];
	std::vector<int>::iterator it;
	for (it = _container.begin() + 1; it != _container.end(); it++) {
		if (*it < min)
			min = *it;
		if (*it > max)
			max = *it;
	}
	return (max - min);
}
