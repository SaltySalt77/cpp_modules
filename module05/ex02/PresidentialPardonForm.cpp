#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5) {
	target = "none";
}

PresidentialPardonForm::PresidentialPardonForm(std::string	target) : Form("PresidentialPardonForm", 25, 5) {
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm	&sForm) : Form("PresidentialPardonForm", 25, 5) {
	this->target = sForm.target;
	this->setIsSigned(sForm.getIsSigned());
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm	&sForm) {
	if (this == &sForm)
		return *this;
	this->target = sForm.target;
	this->setIsSigned(sForm.getIsSigned());
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void	PresidentialPardonForm::execute(Bureaucrat const	&executer) const {
}