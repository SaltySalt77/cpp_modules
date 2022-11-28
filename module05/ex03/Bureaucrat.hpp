#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Form;

class Bureaucrat {
private:
	const std::string	name;
	int				grade;
public:
	Bureaucrat();
	Bureaucrat(std::string	name, int grade);
	Bureaucrat(const Bureaucrat	&bureaucrat);
	Bureaucrat	&operator= (const Bureaucrat	&bureaucrat);
	~Bureaucrat();

	std::string	getName() const;

	int	getGrade() const;
	void	setGrade(int grade);
	void	incrementGrade();
	void	decrementGrade();

	void	signForm(Form &form);

	void	executeForm(Form const	&form);

	class GradeTooHighException : public std::exception {
	public :
		const char * what() const throw();
	};

	class GradeTooLowException  : public std::exception {
	public :
		const char * what() const throw();
	};
};

std::ostream &operator << (std::ostream	&out,	const Bureaucrat	&bureaucrat);

#endif