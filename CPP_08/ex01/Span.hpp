#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
private:
	std::vector<int> _container;
	unsigned int _current_len;
	unsigned int _max_len;

public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	~Span();
	Span&		operator=(const Span& other);
	void		addNumber(int value);
	long long	shortestSpan();
	long long	longestSpan();
	template <typename T>
	void		insert(T begin, T end);
};

template <typename T>
void	Span::insert(T begin, T end) {
	for (T it = begin; it < end; it++)
		addNumber(*it);
}

#endif