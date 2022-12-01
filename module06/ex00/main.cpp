#include "Convert.hpp"
#include <iostream>

int	main(int argc, char	**argv) {

	if (argc != 2) {
		std::cerr << "usage : ./convert <a string to convert into scalar type>" << std::endl;
		return 1;
	}

	std::cout << std::endl;

	Convert	Convert(argv[1]);
	Convert.convertValue();
	Convert.printChar();
	Convert.printInt();
	Convert.printFloat();
	Convert.printDouble();

	std::cout << std::endl;

	return 0;
}