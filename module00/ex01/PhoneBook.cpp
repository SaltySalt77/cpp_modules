#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook() {
	idx = 0;
};

std::string	PhoneBook::getInput(std::string	title) {
	std::string	buffer;

	while (true)
	{
		std::cout << title << " : ";
		std::getline(std::cin, buffer);
		if (buffer.size())
			break;
		std::cout << "The contact can't have empty fields!" << std::endl;
	}
	return buffer;
}

void	PhoneBook::addContact() {
	std::cout << "Restoring on index number " << idx + 1 << " "<< std::endl;
	this->contacts[idx].setFristName(this->getInput("first name"));
	this->contacts[idx].setLastName(this->getInput("last name"));
	this->contacts[idx].setNickname(this->getInput("nickname"));
	this->contacts[idx].setPhoneNbr(this->getInput("phone number"));
	this->contacts[idx].setSecret(this->getInput("darkest secret"));
	idx++;
	if (idx == 8)
		idx = 0;
}

// void	PhoneBook::searchContact() {
	
// }