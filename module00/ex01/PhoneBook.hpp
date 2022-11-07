#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook {
	Contact		contacts[8];
	int			idx;
public :
	void	addContact();
	void	searchContact();
	void	showAll();
	std::string	getInput(std::string	title);
	PhoneBook();
};

#endif