#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern	&intern) {
}

Intern	&Intern::operator=(const Intern	&intern) {
	return *this;
}

Intern::~Intern() {
}

void	Intern::makeForm(const std::string	name, const std::string	target) {
	std::string	formLst[3] = { "ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm" };
	void	(Form::*fptrs[3])(std::string) = { &(ShrubberyCreationForm::getNewForm(std::string)),  }

}