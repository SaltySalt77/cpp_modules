#include "Form.hpp"
#include <iostream>

Form::Form() : name("unnamed"), toSign(150), toExecute(150) {
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

void	Form::setIsSigned(bool tf) {
	isSigned = tf;
}

int	Form::validateGrade(const int	grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return grade;
}

bool	Form::isHigher(int	required, int	grade) const {
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

const char	*Form::FormNotSigned::what() const throw() {
	return "The form is not signed. 📃\n";
}

const char	*Form::OpenFailed::what() const throw() {
	return "File open failed. ☹️\n";
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