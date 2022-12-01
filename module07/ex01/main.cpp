#include "iter.hpp"

int main() {
	{
		std::string	test = "test";
		const char	*a = test.c_str();

		::iter(a, 2, print);
		::iter(a, 5, print);
		std::cout << std::endl;
	}
	{
		int	arr[4];
		for (int i = 0; i < 4; i++)
			arr[i] = i + 1;
		::iter(arr, 2, print);
		::iter(arr, 5, print);
		std::cout << std::endl;
	}
	{
		float	arr[4];
		for (int i = 0; i < 4; i++)
			arr[i] = i + 1;
		::iter(arr, 2, print);
		::iter(arr, 5, print);
		std::cout << std::endl;
	}
	{
		double	arr[4];
		for (int i = 0; i < 4; i++)
			arr[i] = i + 1;
		::iter(arr, 2, print);
		::iter(arr, 5, print);
		std::cout << std::endl;
	}
	{
		std::string	arr[4] = {"one", "two", "three", "four" };
		::iter(arr, 2, print);
		::iter(arr, 5, print);
		std::cout << std::endl;
	}
	return 0;
}