#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat	a("A", 1);
	Bureaucrat	b("B", 150);
	Bureaucrat	c("C", 200);

	std::cout << std::endl << a << b << c << std::endl;

	a.incrementGrade();
	b.decrementGrade();

	std::cout << std::endl << a << b << std::endl;

	a.decrementGrade();
	b.incrementGrade();

	std::cout << a << b << std::endl;

	return 0;
}