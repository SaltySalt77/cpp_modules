#include <iostream>
#include <string>

int main() {
	std::string	brain("HI THIS IS BRAIN");
	std::string *brainPtr = &brain;
	std::string &brainRef = brain;

	std::cout << "The memory address of the string variable : " << &brain << std::endl;
	std::cout << "The memory address held by stringPTR      : " << brainPtr << std::endl;
	std::cout << "The memory address held by stringREF      : " << &brainRef << std::endl;
	
	std::cout << std::endl;

	std::cout << "The value of the string variable          : " << brain << std::endl;
	std::cout << "The value held by stringPTR               : " << brain << std::endl;
	std::cout << "The value held by stringREF               : " << brain << std::endl;
}