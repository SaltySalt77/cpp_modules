#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook() {
	isFull = false;
	idx = 0;
};

std::string	PhoneBook::getInput(std::string	title) {
	std::string	buffer;

	while (true) {
		std::cout << title << " : ";
		std::getline(std::cin, buffer);
		if (buffer == "")
			break ;
		if (buffer.size())
			break;
		std::cerr << "The contact can't have empty fields!" << std::endl;
	}
	std::cin.clear();
	return buffer;
}

std::string	PhoneBook::getOutput(std::string	content) {
	int			len;
	std::string	fmt_contant;

	len = content.length();
	if (len < 10) {
		while (len != 10) {
			fmt_contant.push_back(' ');
			len++;
		}
		fmt_contant.append(content);
	}
	else if (len > 10) {
		fmt_contant = content.substr(0, 9); 
		fmt_contant.push_back('.');
	}
	else
		return content;
	return fmt_contant;
}

void	PhoneBook::addContact() {
	std::cout << std::endl;
	std::cout << "Restoring on index number " << idx + 1 << " "<< std::endl;
	this->contacts[idx].setFristName(this->getInput("first name    "));
	this->contacts[idx].setLastName(this->getInput("last name     "));
	this->contacts[idx].setNickname(this->getInput("nickname      "));
	this->contacts[idx].setPhoneNbr(this->getInput("phone number  "));
	this->contacts[idx].setSecret(this->getInput("darkest secret"));
	idx = (idx + 1) % 8;
	if (idx == 0)
		isFull = true;
}

void	PhoneBook::searchContact() {
	std::string	ret;
	int			idx;
	int	i;

	i = 0;
	idx = 0;
	std::cout << std::endl;
	if (this->idx == 0 && !isFull) {
		std::cerr << "There's NOTHING RESTORED in the phone book." << std::endl;
		std::cerr << "Please retry after adding contacts." << std::endl;
		return ;
	}
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	while (i < this->idx || (isFull && i < 8)) {
		std::cout << "         " << i + 1 << "|";
		std::cout << this->getOutput(contacts[i].getFristName()) << "|";
		std::cout << this->getOutput(contacts[i].getLastName()) << "|";
		std::cout << this->getOutput(contacts[i].getNickname()) << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		i++;
	}
	std::cout << std::endl;
	std::cout << "Put index which you want to search." << std::endl;
	while (true) {
		ret = this->getInput("Index");
		if (ret == "")
			break ;
		if (ret.length() == 1) {
			idx = ret[0] - '0';
			if (idx > 0 && (idx <= this->idx || (isFull && idx < 9)))
				break ;
		}
		std::cerr << "The index is OUT of RANGE!" << std::endl;
		std::cerr << "Please put again." << std::endl;
	}
	if (idx) {
		std::cout << std::endl;
		std::cout << "first name     : " << contacts[idx - 1].getFristName() << std::endl;
		std::cout << "last name      : " << contacts[idx - 1].getLastName() << std::endl;
		std::cout << "nickname       : " << contacts[idx - 1].getNickname() << std::endl;
		std::cout << "phone nunber   : " << contacts[idx - 1].getPhoneNbr() << std::endl;
		std::cout << "darkest Secret : " << contacts[idx - 1].getSecret() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "SEARCH FINISHED" << std::endl;
}