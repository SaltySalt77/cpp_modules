#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Anonymous") {
	this->setGrade(150);
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
	try {
		if (grade < 1)
			throw	GradeTooHighException();
		else if (grade > 150)
			throw	GradeTooLowException();
		this->grade = grade;
	}
	catch (Bureaucrat::GradeTooHighException	&e) {
		std::cerr << e.what();
		this->grade = 1;
	}
	catch (Bureaucrat::GradeTooLowException	&e) {
		std::cerr << e.what();
		this->grade = 150;
	}
}

void	Bureaucrat::incrementGrade() {
	setGrade(this->grade - 1);
}

void	Bureaucrat::decrementGrade() {
	setGrade(this->grade + 1);
}

void	Bureaucrat::signForm(Form	&form) {
	try {
		form.beSigned(*this);
		std::cout << getName() << ", signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << getName() << " couldn't sign " << form.getName() << " because " << e.what();
	}
}

void	Bureaucrat::executeForm(Form const	&form) {
	try {
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << " ✔️" << std::endl;
	} catch (const std::exception	&e){
		std::cerr << name << " failed to execute " << form.getName() << ". ☹️ " << e.what();
	}
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high. The highest grade is 1\n";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low. The lowest grade is 150\n";
}

std::ostream &operator << (std::ostream	&out,	const Bureaucrat	&bureaucrat) {
	out << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade()  << "." << std::endl;
	return out;
}
