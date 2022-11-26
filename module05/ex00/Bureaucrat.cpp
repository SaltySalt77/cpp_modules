#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Anonymous"), grade(150) {
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat	&bureaucrat) : name(bureaucrat.getName()) {
	this->setGrade(bureaucrat.getGrade());
}

Bureaucrat	&Bureaucrat::operator= (const Bureaucrat	&bureaucrat) {
	if (this == &bureaucrat)
		return *this;
	this->setGrade(bureaucrat.getGrade());
	return *this;
}

Bureaucrat::~Bureaucrat() {
}

std::string	Bureaucrat::getName() const {
	return name;
}

int	Bureaucrat::getGrade() const {
	return grade;
}

void	Bureaucrat::setGrade(int grade) {
	if (grade < 1)
		throw	GradeTooHighException();
	else if (grade > 150)
		throw	GradeTooLowException();
	this->grade = grade;
}

void	Bureaucrat::incrementGrade() {
	if (grade == 1)
		throw	GradeTooHighException();
	grade--;
}

void	Bureaucrat::decrementGrade() {
	if (grade == 150)
		throw	GradeTooLowException();
	grade++;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high. The highest Grade is 1.\n";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low. The lowest Grade is 150.\n";
}

std::ostream &operator << (std::ostream	&out,	const Bureaucrat	&bureaucrat) {
	out << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade()  << "." << std::endl;
	return out;
}
