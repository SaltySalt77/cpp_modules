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

int	Span::shortestSpan() {
	std::vector<int>			sorted(vec);
	std::vector<int>::iterator	cur;

	try {
		if (vec.size() < 2)
			throw std::logic_error("Size is too small\n");
	}
	catch (std::exception	&e) {
		std::cerr << e.what();
		return -1;
	}
	std::sort(sorted.begin(), sorted.end());
	cur = sorted.begin();
	int small = *(sorted.end()) - *(sorted.begin());
	for (; cur != sorted.end(); cur++) {
		int tmp = *(cur + 1) - *cur;
		if (tmp < small)
			small = tmp;
	}
	return small;
}

int Span::longestSpan() {
	std::vector<int>			sorted(vec);

	try {
		if (vec.size() < 2)
			throw std::logic_error("Size is too small\n");
	}
	catch (std::exception	&e) {
		std::cerr << e.what();
		return -1;
	}
	std::sort(sorted.begin(), sorted.end());
	return *(sorted.end()) - *(sorted.begin());
}