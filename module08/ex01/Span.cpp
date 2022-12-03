#include "Span.hpp"
#include <iostream>

Span::Span() {
	maxSize = 0;
}

Span::Span(unsigned int	N) {
	maxSize = N;
}

Span::Span(const Span	&span) {
	this->vec = span.vec;
	this->maxSize = span.maxSize;
}

Span	&Span::operator=(const Span	&span) {
	if (this == &span)
		return *this;
	this->vec = span.vec;
	this->maxSize = span.maxSize;
	return *this;
}

Span::~Span() {
}

void	Span::addNumber(int	N) {
	try {
		if (vec.size() == maxSize)
			throw std::logic_error("Already full\n");
		vec.push_back(N);
	}
	catch (std::exception	&e) {
		std::cerr << e.what();
	}
}

void	Span::addNumber(int min, int max) {
	try {
		if (vec.size() == maxSize)
			throw std::logic_error("Already full\n");
		for (; min <= max; min++) {
			if (vec.size() == maxSize)
				throw std::logic_error("Already full\n");
			vec.push_back(min);
		}
	}
	catch (std::exception	&e) {
		std::cerr << e.what();
	}
}

void	Span::addNumber(int	*arr, unsigned int	size) {

	try {
		if (vec.size() + size >= maxSize)
			throw std::logic_error("Already full\n");
		vec.insert(vec.end(), arr, arr + size);
	}
	catch (std::exception	&e) {
		std::cerr << e.what();
		size = maxSize - vec.size();
		vec.insert(vec.end(), arr, arr + size);
	}
}

long long	Span::shortestSpan() {
	std::vector<int>			sorted(vec);
	std::vector<int>::iterator	cur;

	if (vec.size() < 2)
		throw std::logic_error("Size is too small\n");
	std::sort(sorted.begin(), sorted.end());
	cur = sorted.begin();
	long long small = *(sorted.end() - 1) - *(sorted.begin());
	for (; cur + 1 != sorted.end(); cur++) {
		long long tmp = *(cur + 1) - *cur;
		if (tmp < small)
			small = tmp;
	}
	return small;
}

long long Span::longestSpan() {
	std::vector<int>			sorted(vec);

	if (vec.size() < 2)
		throw std::logic_error("Size is too small\n");
	std::sort(sorted.begin(), sorted.end());
	return *(sorted.end() - 1) - *(sorted.begin());
}