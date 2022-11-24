#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
	type = "cat";
	std::cout << "Generating one cat. 🐈" << std::endl;
}

WrongCat::WrongCat(const WrongCat	&wrongCat) : WrongAnimal() {
	this->type = wrongCat.type;
	std::cout << "Creating cat copied version of 🐈" << type << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat	&wrongCat) {
	if (this == &wrongCat)
		return *this;
	this->type = wrongCat.type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat is disappearing for good. 🐈" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "🐱 MEEEEEEEEEEOOOOOOOOWWWWW 🐱" << std::endl;
}
