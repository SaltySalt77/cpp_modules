#include "PhoneBook.hpp"
#include <string>

int	main() {
	PhoneBook	phoneBook;
	std::string	buffer;

	while (true) {
		std::cout << "Insert Menu" << std::endl;
		std::getline(std::cin, buffer);
		if (buffer == "ADD")
			phoneBook.addContact();
		else if (buffer == "SEARCH")
			phoneBook.searchContact();
		else if (buffer == "EXIT" || std::cin.eof())
			break ;
		std::cout << "----------------------------------------------" << std::endl;
	}
	return 0;
}