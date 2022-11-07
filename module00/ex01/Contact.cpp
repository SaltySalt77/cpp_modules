#include "Contact.hpp"

void	Contact::setFristName(std::string	firstName) {
	this->firstName = firstName;
}

void	Contact::setLastName(std::string	lastName) {
	this->lastName = lastName;
}

void	Contact::setNickname(std::string	nickname) {
	this->nickname = nickname;
}

void	Contact::setPhoneNbr(std::string	phoneNbr) {
	this->phoneNbr = phoneNbr;
}

void	Contact::setSecret(std::string	darkestSecret) {
	this->darkestSecret = darkestSecret;
}

std::string	Contact::getFristName() {
	return this->firstName;
}

std::string Contact::getLastName() {
	return this->lastName;
}

std::string Contact::getNickname() {
	return this->nickname;
}

std::string Contact::getPhoneNbr() {
	return this->phoneNbr;
}

std::string Contact::getSecret() {
	return this->darkestSecret;
}