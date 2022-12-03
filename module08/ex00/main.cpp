#include <iostream>
#include <iomanip>
#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <cstdlib>
#include <ctime>

const char	*NoOccurrenceFound::what() const throw() {
	return "No occurrence found\n";
}


int	main() {
	srand(time(NULL));

	{
		std::cout << std::endl << "==============================" << std::endl << std::endl;
		std::vector<int>	v;

		for (int i = 0; i < 10; i++)
			v.push_back(rand() % 11);

		std::vector<int>::iterator	iter;

		iter = v.begin();

		for (; iter != v.end(); iter++) {
			std::cout << std::setw(2) << *iter;
			std::cout << " ";
		}
		std::cout << std::endl;

		try {
			iter = easyfind(v, 7);
			std::cout << "easyfind found " << *iter << std::endl;
		}
		catch (std::exception	&e) {
			std::cerr << e.what();
		}
	}
	{
		std::list<int>	v;

		for (int i = 0; i < 10; i++)
			v.push_back(rand() % 11);

		std::list<int>::iterator	iter;

		iter = v.begin();

		std::cout << std::endl << "==============================" << std::endl << std::endl;

		for (; iter != v.end(); iter++) {
			std::cout << std::setw(2) << *iter;
			std::cout << " ";
		}
		std::cout << std::endl;

		try {
			iter = easyfind(v, 7);
			std::cout << "easyfind found " << *iter << std::endl;
		}
		catch (std::exception	&e) {
			std::cerr << e.what();
		}
	}
	{
		std::deque<int>	v;

		for (int i = 0; i < 10; i++)
			v.push_back(rand() % 11);

		std::deque<int>::iterator	iter;

		iter = v.begin();

		std::cout << std::endl << "==============================" << std::endl << std::endl;

		for (; iter != v.end(); iter++) {
			std::cout << std::setw(2) << *iter;
			std::cout << " ";
		}
		std::cout << std::endl;

		try {
			iter = easyfind(v, 7);
			std::cout << "easyfind found " << *iter << std::endl;
		}
		catch (std::exception	&e) {
			std::cerr << e.what();
		}

		std::cout << std::endl << "==============================" << std::endl << std::endl;
	}
	return 0;
}