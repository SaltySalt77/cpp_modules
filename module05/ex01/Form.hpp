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

	int	validateGrade(const int grade);

	bool	isHigher(int required, int grade);

	void	beSigned(const Bureaucrat	&bureaucrat);

	class GradeTooHighException : public std::exception {
	public :
		const char * what() const throw();
	};

	class GradeTooLowException  : public std::exception {
	public :
		const char * what() const throw();
	};
};

std::ostream	&operator<< (const std::ostream	&out, const Form	&form);

#endif