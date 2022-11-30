#include "RobotomyRequestForm.hpp"
#include "stdlib.h" // 헤더 변경
#include "time.h"

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
	if (this == &rForm
		|| getToSign() != rForm.getToSign()
		|| getToExecute() != rForm.getToExecute()
		|| getName() != rForm.getName())
		return *this;
	target = rForm.target;
	setIsSigned(rForm.getIsSigned());
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void	RobotomyRequestForm::execute(Bureaucrat const	&executer) const {
	srand(time(NULL));

	if (!getIsSigned())
		throw FormNotSigned();
	isHigher(getToExecute(), executer.getGrade());
	std::cout << "* The Sound of DRILLING NOISE *" << std::endl;
	if (rand() % 2)
		std::cout << "Robotomizing " << target << " failed. ☹️" << std::endl;
	else
		std::cout << target << " has been robotomized successfully. 🤖" << std::endl;
}
