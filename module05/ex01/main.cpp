#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	Bureaucrat	a("A", 1);
	Bureaucrat	b("B", 150);

	std::cout << a << b << std::endl;

	Form	formA("formA", 1, 1);
	Form	formB("formB", 150, 150);

	std::cout << formA << formB << std::endl;

	b.signForm(formA);
	std::cout << formA << std::endl;
	a.signForm(formA);
	std::cout << formA << std::endl;

	b.signForm(formB);
	std::cout << formB << std::endl;
	return 0;
}