#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Form {
private :
	const std::string	name;
	bool		isSigned;
	const int	toSign;
	const int	toExecute;
public :
	Form();
	Form(const std::string	name, int toSign, int toExecute);
	Form(const Form	&form);
	Form	&operator=(const Form	&form);
	~Form();

	std::string	getName() const;
	bool	getIsSigned() const;
	int	getToSign() const;
	int	getToExecute() const;

	void	setIsSigned(bool	tf);

	int	validateGrade(const int grade);

	bool	isHigher(int required, int grade) const;

	void	beSigned(const Bureaucrat	&bureaucrat);

	virtual void	execute(Bureaucrat const	&executer) const = 0;

	class GradeTooHighException : public std::exception {
	public :
		const char * what() const throw();
	};

	class GradeTooLowException  : public std::exception {
	public :
		const char * what() const throw();
	};

	class FormNotSigned : public std::exception {
	public :
		const char * what() const throw();
	};

	class OpenFailed : public std::exception {
	public :
		const char * what() const throw();
	};
};

std::ostream	&operator<< (std::ostream	&out, const Form	&form);

#endif