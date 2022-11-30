#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main() {
	Bureaucrat	a("A", 1);
	Bureaucrat	b("B", 20);
	Bureaucrat	c("C", 40);
	Bureaucrat	d("D", 60);
	Bureaucrat	e("E", 120);
	Bureaucrat	f("F", 140);
	Bureaucrat	g("G", 150);

	std::cout << a << b << c << d << e << f << g << std::endl;

	Intern someRandomIntern;
	Form	*sForm;
	Form	*rForm;
	Form	*pForm;
	Form	*nForm;

	sForm = someRandomIntern.makeForm("shrubbery creation", "Home");
	rForm = someRandomIntern.makeForm("robotomy request", "Bender");
	pForm = someRandomIntern.makeForm("presidential pardon", "Bender");
	nForm = someRandomIntern.makeForm("","");
	(void) nForm;

	std::cout << std::endl << *sForm << *rForm << *pForm << std::endl;

	g.executeForm(*sForm);
	g.signForm(*sForm);

	std::cout << std::endl;

	f.signForm(*sForm);
	f.executeForm(*sForm);

	std::cout << std::endl;

	e.executeForm(*sForm);
	e.executeForm(*rForm);
	e.signForm(*rForm);

	std::cout << std::endl;

	d.signForm(*rForm);
	d.executeForm(*rForm);

	std::cout << std::endl;

	c.executeForm(*rForm);
	c.executeForm(*pForm);
	c.signForm(*pForm);

	std::cout << std::endl;

	b.signForm(*pForm);
	b.executeForm(*pForm);

	std::cout << std::endl;

	a.executeForm(*pForm);

	delete sForm;
	delete rForm;
	delete pForm;
	return 0;
}