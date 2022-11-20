#include <iostream>
#include <iomanip>
#include "Fixed.hpp"

int main( void ) {

	std::cout << "test code output from subject" << std::endl;
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}

	std::cout << "=========================================" << std::endl;
	std::cout << "test code output" << std::endl << std::endl;

	std::cout << "comparison operator" << std::endl << std::endl;
	{
		Fixed	a(1);
		Fixed	b(2.5f);

		std::cout << "a = " << a << " | b = " << b << std::endl << std:: endl;

		std::cout << "a > b :" << (a > b) << std::endl;
		std::cout << "a < b :" << (a < b) << std::endl;
		std::cout << "a >= b :" << (a >= b) << std::endl;
		std::cout << "a <= b :" << (a <= b) << std::endl;
		std::cout << "a == b :" << (a == b) << std::endl;
		std::cout << "a != b :" << (a != b) << std::endl;
	}
	std::cout << std::endl;

	std::cout << "arithmetic operator" << std::endl << std::endl;
	{
		Fixed	a(2);
		Fixed	b(2.4f);

		std::cout << "a = " << a << " | b = " << b << std::endl << std::endl;

		std::cout << "a + b = " << a + b << std::endl;
		std::cout << "a - b = " << a - b << std::endl;
		std::cout << "a * b = " << a * b << std::endl;
		std::cout << "a / b = " << a / b << std::endl;
	}
	std::cout << std::endl;

	std::cout << "prefix / postfix operator" << std::endl << std::endl;
	{
		Fixed	a(1);
		Fixed	b(4.2f);

		std::cout << "a = " << a << " | b = " << b << std::endl << std::endl;

		std::cout << "a++ | b++ " << std::endl;
		std::cout << a++ << " | " << b++ << std::endl;
		std::cout << a++ << " | " << b++ << std::endl << std::endl;

		std::cout << "a = " << a << " | b = " << b << std::endl << std::endl;

		std::cout << "++a | ++b " << std::endl;
		std::cout << ++a << " | " << ++b << std::endl << std::endl;


		std::cout << "a = " << a << " | b = " << b << std::endl << std::endl;

		std::cout << "a-- | b-- " << std::endl;
		std::cout << a-- << " | " << b-- << std::endl;
		std::cout << a-- << " | " << b-- << std::endl << std::endl;

		std::cout << "a = " << a << " | b = " << b << std::endl << std::endl;

		std::cout << "--a | --b " << std::endl;
		std::cout << --a << " | " << --b << std::endl;
		std::cout << --a << " | " << --b << std::endl << std::endl;

	}
	return 0;
}