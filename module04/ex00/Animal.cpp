#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
	type = "animal";
	std::cout << "Generating one animal." << std::endl;
}

Animal::Animal(const Animal	&animal) {
	this->type = animal.type;
	std::cout << "Creating animal copied version of " << type << std::endl;
}

Animal	&Animal::operator=(const Animal	&animal) {
	if (this == &animal)
		return *this;
	this->type = animal.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal is disappering for good" << std::endl;
}

void	Animal::makeSound() const {
	std::cout << "* Loud sounds made by various animals *" << std::endl;
}

std::string	Animal::getType() const {
	return type;
}

void	Animal::setType(std::string	type) {
	this->type = type;
}
