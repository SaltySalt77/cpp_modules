#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
	type = "cat";
	std::cout << "Generating one cat. 🐈" << std::endl;
	brain = new Brain;
}

Cat::Cat(const Cat	&cat) : Animal() {
	this->type = cat.type;
	std::cout << "Creating cat copied version of 🐈" << type << std::endl;
	this->brain = new Brain;
	this->brain = cat.brain;
}

Cat	&Cat::operator=(const Cat	&cat) {
	if (this == &cat)
		return *this;
	this->type = cat.type;
	delete this->brain;
	this->brain = new Brain;
	this->brain = cat.brain;
	return *this;
}

Cat::~Cat() {
	delete	brain;
	std::cout << "Cat is disappearing for good. 🐈" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "🐱 MEEEEEEEEEEOOOOOOOOWWWWW 🐱" << std::endl;
}
