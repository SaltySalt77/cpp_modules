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

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm	&pForm) {
	if (this == &pForm
		|| getToSign() != pForm.getToSign()
		|| getToExecute() != pForm.getToExecute()
		|| getName() != pForm.getName())
		return *this;
	target = pForm.target;
	setIsSigned(pForm.getIsSigned());
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void	PresidentialPardonForm::execute(Bureaucrat const	&executer) const {
	if (!getIsSigned())
		throw FormNotSigned();
	isHigher(getToExecute(), executer.getGrade());
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}