#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
	std::string	phoneNbr;
	std::string	firstName;
	std::string	lastName;
	std::string	darkestSecret;
public :
	void	setPhoneNbr(std::string	phoneNbr);
	void	setFristName(std::string firstName);
	void	setLastName(std::string	lastName);
	void	setSecret(std::string	darkestSecret);
	std::string	getPhoneNbr();
	std::string	getFristName();
	std::string	getLastName();
	std::string	getSecret();
};

#endif
