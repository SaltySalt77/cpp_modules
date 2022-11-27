#ifndef	PRESIDENTIALPARDONFORM_HPP
# define	PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
private :
	std::string	target;
public :
	PresidentialPardonForm();
	PresidentialPardonForm(std::string	target);
	PresidentialPardonForm(const PresidentialPardonForm	&pForm);
	PresidentialPardonForm	&operator=(const PresidentialPardonForm	&pForm);
	~PresidentialPardonForm();

};

#endif