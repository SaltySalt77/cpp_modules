#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45) {
	target = "none";
}

RobotomyRequestForm::RobotomyRequestForm(std::string	target) : Form("RobotomyRequestForm", 72, 45) {
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm	&rForm) : Form("RobotomyRequestForm", 72, 45) {
	this->target = rForm.target;
	this->setIsSigned(rForm.getIsSigned());
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm	&rForm) {
	if (this == &rForm)
		return *this;
	this->target = rForm.target;
	this->setIsSigned(rForm.getIsSigned());
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

