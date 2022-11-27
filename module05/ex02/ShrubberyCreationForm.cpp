#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137) {
	target = "none";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string	target) : Form("ShrubberyCreationForm", 145, 137) {
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm	&sForm) : Form("ShrubberyCreationForm", 145, 137) {
	this->target = sForm.target;
	this->setIsSigned(sForm.getIsSigned());
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm	&sForm) {
	if (this == &sForm)
		return *this;
	this->target = sForm.target;
	this->setIsSigned(sForm.getIsSigned());
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

