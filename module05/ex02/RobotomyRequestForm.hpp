#ifndef	ROBOTOMYREQUESTFORM_HPP
# define	ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form {
private :
	std::string	target;
public :
	RobotomyRequestForm();
	RobotomyRequestForm(std::string	target);
	RobotomyRequestForm(const RobotomyRequestForm	&rForm);
	RobotomyRequestForm	&operator=(const RobotomyRequestForm	&rForm);
	~RobotomyRequestForm();

};

#endif