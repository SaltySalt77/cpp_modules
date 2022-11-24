#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {
	type = "animal";
	std::cout << "Generating one wrongAnimal." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal	&wrongAnimal) {
	this->type = wrongAnimal.type;
	std::cout << "Creating wrongAnimal copied version of " << type << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal	&wrongAnimal) {
	if (this == &wrongAnimal)
		return *this;
	this->type = wrongAnimal.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal is disappearing for good" << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << "* Loud sounds made by various wrongAnimals *" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return type;
}

void	WrongAnimal::setType(std::string	type) {
	this->type = type;
}
