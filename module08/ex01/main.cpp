#include "Span.hpp"
#include <iostream>

int main() {
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		try {
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::exception	&e) {
			std::cerr << e.what();
		}
		try {
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception	&e) {
			std::cerr << e.what();
		}
		std::cout << std::endl << "====================================" << std::endl;
		std::cout << std::endl;
	}
	{
		Span sp = Span(10);

		sp.addNumber(0, 20);
		try {
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::exception	&e) {
			std::cerr << e.what();
		}
		try {
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception	&e) {
			std::cerr << e.what();
		}
		std::cout << std::endl << "====================================" << std::endl;
		std::cout << std::endl;
	}
	{
		Span sp = Span(100000);

		sp.addNumber(1, 100000);
		try {
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::exception	&e) {
			std::cerr << e.what();
		}
		try {
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception	&e) {
			std::cerr << e.what();
		}
		std::cout << std::endl << "====================================" << std::endl;
		std::cout << std::endl;
	}
	{
		int arr[] = { 1, 4, 5, 9, 0};
		Span sp = Span(2);

		sp.addNumber(arr, 5);
		try {
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::exception	&e) {
			std::cerr << e.what();
		}
		try {
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception	&e) {
			std::cerr << e.what();
		}
		std::cout << std::endl << "====================================" << std::endl;
		std::cout << std::endl;
	}
	{
		Span sp = Span(0);

		sp.addNumber(1);
		try {
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::exception	&e) {
			std::cerr << e.what();
		}
		try {
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception	&e) {
			std::cerr << e.what();
		}
		std::cout << std::endl << "====================================" << std::endl;
		std::cout << std::endl;
	}
	{
		Span sp = Span(1);

		sp.addNumber(1);
		sp.addNumber(1);
		try {
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::exception	&e) {
			std::cerr << e.what();
		}
		try {
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception	&e) {
			std::cerr << e.what();
		}
	}
	return 0;
}