#include "Convert.hpp"
#include <cmath>

int	main(int argc, char	**argv) {

	if (argc != 2) {
		std::cerr << "usage : ./convert <a string to convert into scalar type>" << std::endl;
		return 1;
	}

	Convert	Convert(argv[1]);
	Convert.convertValue();
	Convert.printChar();
	Convert.printInt();
	Convert.printFloat();
	Convert.printDouble();

	std::cout << std::endl << std::endl;

	double test = 111111111111111;

	std::cout << test << std::endl;
	return 0;
}