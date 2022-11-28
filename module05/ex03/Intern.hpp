#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>

class Intern {
public:
	Intern();
	Intern(const Intern	&intern);
	Intern	&operator= (const Intern	&intern);
	~Intern();

	void	makeForm(const std::string	name, const std::string	target);
};

#endif