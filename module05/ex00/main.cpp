#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat	a("A", 1);
	Bureaucrat	b("B", 150);
	Bureaucrat	c("C", 200);

	std::cout << a << b << c << std::endl;

	try {
		a.incrementGrade();
		b.decrementGrade();
	} catch (const std::exception	&e) {
		std::cout << e.what();
	}

	std::cout << a << b << std::endl;


	try {
		a.decrementGrade();
		b.incrementGrade();
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << a << b << std::endl;

	return 0;
}