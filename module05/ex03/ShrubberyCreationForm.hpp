#ifndef	SHRUBBERYCREATIONFORM_HPP
# define	SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
private :
	std::string	target;
public :
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string	target);
	ShrubberyCreationForm(const ShrubberyCreationForm	&sForm);
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm	&sForm);
	~ShrubberyCreationForm();

	void	execute(Bureaucrat const	&executer) const;

	ShrubberyCreationForm	*getNewForm(std::string	target);
};

#endif