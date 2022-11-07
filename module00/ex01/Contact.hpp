#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNbr;
	std::string	darkestSecret;
public :
	void	setFristName(std::string firstName);
	void	setLastName(std::string	lastName);
	void	setNickname(std::string	nickname);
	void	setPhoneNbr(std::string	phoneNbr);
	void	setSecret(std::string	darkestSecret);
	std::string	getFristName();
	std::string	getLastName();
	std::string	getNickname();
	std::string	getPhoneNbr();
	std::string	getSecret();
};

#endif
