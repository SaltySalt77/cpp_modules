#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {
	Bureaucrat	a("A", 1);
	Bureaucrat	b("B", 20);
	Bureaucrat	c("C", 40);
	Bureaucrat	d("D", 60);
	Bureaucrat	e("E", 120);
	Bureaucrat	f("F", 140);
	Bureaucrat	g("G", 150);

	std::cout << a << b << c << d << e << f << g << std::endl;

	PresidentialPardonForm	pForm("Buzz");
	RobotomyRequestForm		rForm("Robot");
	ShrubberyCreationForm	sForm("Home");

	std::cout << pForm << rForm << sForm << std::endl;

	g.executeForm(pForm);
	g.signForm(pForm);

	std::cout << std::endl;

	f.signForm(pForm);
	f.executeForm(pForm);

	std::cout << std::endl;

	e.executeForm(pForm);
	e.executeForm
	return 0;
}