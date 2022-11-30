#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "Form.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern	&intern);
	Intern	&operator= (const Intern	&intern);
	~Intern();

	Form	*makeForm(const std::string	name, const std::string	target);

	class FormNotExist : public std::exception {
	public :
		const char * what() const throw();
	};
};

#endif