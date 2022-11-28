#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern	&intern) {
	(void) intern;
}

Intern	&Intern::operator=(const Intern	&intern) {
	(void) intern;
	return *this;
}

Intern::~Intern() {
}

Form	*getNewSForm(const std::string	target) {
	return (Form *) new ShrubberyCreationForm(target);
}

Form	*getNewRForm(const std::string	target) {
	return (Form *) new RobotomyRequestForm(target);
}

Form	*getNewPForm(const std::string	target) {
	return (Form *) new PresidentialPardonForm(target);
}

Form	*Intern::makeForm(const std::string	name, const std::string	target) {
	std::string	formLst[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
	Form * (*fptr[3]) (const std::string) = { &getNewSForm, &getNewRForm, &getNewPForm };

	int i = 0;
	while (i < 3) {
		if (!formLst[i].compare(name)) {
			std::cout << "Intern creates " << name << std::endl;
			return fptr[i](target);
		}
		i++;
	}
	throw FromNotExist();
}

const char	*Intern::FromNotExist::what() const throw() {
	return "The Form does Not Exist. ☠️\n";
}