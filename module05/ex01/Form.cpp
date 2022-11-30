#include "Form.hpp"
#include <iostream>

Form::Form() : name("unnamed"), toSign(validateGrade(150)), toExecute(validateGrade(150)) {
	isSigned = false;
}

Form::Form(const std::string	name, int toSign, int toExecute)
	: name(name), toSign(validateGrade(toSign)),
	toExecute(validateGrade(toExecute)) {
	isSigned = false;
}

Form::Form(const Form &form)
	: name(form.getName()), toSign(validateGrade(form.getToSign())),
	toExecute(validateGrade(form.getToExecute())) {
	isSigned = form.getIsSigned();
}

Form	&Form::operator=(const Form	&form) {
	if (this == &form
		|| toSign != form.getToSign()
		|| toExecute != form.getToExecute()
		|| name != form.getName())
		return *this;
	isSigned = form.getIsSigned();
	return *this;
}

Form::~Form() {
}

std::string	Form::getName() const {
	return name;
}

bool	Form::getIsSigned() const {
	return isSigned;
}

int	Form::getToSign() const {
	return toSign;
}

int	Form::getToExecute() const {
	return toExecute;
}

int	Form::validateGrade(const int	grade) {
	try {
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
	}
	catch (Form::GradeTooHighException	&e) {
		std::cerr << e.what();
		return 1;
	}
	catch (Form::GradeTooLowException	&e) {
		std::cerr << e.what();
		return 150;
	}
	return grade;
}

bool	Form::isHigher(int	required, int	grade) {
	if (required >= grade)
		return true;
	throw	GradeTooLowException();
}

void	Form::beSigned(const Bureaucrat	&bureaucrat) {
	if (isHigher(toSign, bureaucrat.getGrade()))
		isSigned = true;
}

const char	*Form::GradeTooHighException::what() const throw() {
	return "Grade is too High.\n";
}

const char	*Form::GradeTooLowException::what() const throw() {
	return "Grade is too Low.\n";
}

std::ostream	&operator <<(std::ostream	&out, const Form	&form) {
	out << "Form " << form.getName() << " is ";
	if (form.getIsSigned())
		out << "signed. ";
	else
		out << "unsigned. ";
	out << "And it requires grade [" << form.getToSign() << "] to be signed, grade ["
		<< form.getToExecute() << "] to be executed." << std::endl;
	return out;
}