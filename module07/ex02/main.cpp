#include <iostream>
#include "Array.hpp"
#include <sstream>

#define MAX_VAL 750
int main(int argc, char **argv)
{
	{
		(void) argc;
		(void) argv;
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}

		// coded by hyna

		for (unsigned int i = 0 ; i < numbers.size(); i++) {
			std::cout << numbers[i] << std::endl;
		}

		delete [] mirror;//
	}

	{
		Array<float> array;

		array[0] = 1;
		for (unsigned int i = 0; i < array.size(); i++) {
			std::cout << array[i] << std::endl;
		}
		try {
			array[1] = 0;
		}
		catch (std::exception	&e) {
			std::cout << e.what();
		}

		Array<std::string> sArray(10);

		for (unsigned int i = 0; i < sArray.size(); i++) {
			std::stringstream	ss;
			ss << i;
			sArray[i] = ss.str();
		}

		for (unsigned int i = 0; i < sArray.size(); i++) {
			std::cout << sArray[i] << std::endl;
		}
	}
	return 0;
}