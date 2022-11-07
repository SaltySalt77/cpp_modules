#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook {
	Contact		contacts[8];
	bool		isFull;
	int			idx;
public :
	void	addContact();
	void	searchContact();
	void	showAll();
	std::string	getInput(std::string	title);
	std::string	getOutput(std::string	content);
	PhoneBook();
};

#endif