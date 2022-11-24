#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
	type = "dog";
	std::cout << "Generating one dog." << std::endl;
}

Dog::Dog(const Dog	&dog) {
	this->type = dog.type;
	std::cout << "Creating dog copied version of " << type << std::endl;
}

Dog	&Dog::operator=(const Dog	&dog) {
	if (this == &dog)
		return *this;
	this->type = dog.type;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog is disappearing for good" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "🐶 WOOF WOOF 🐶" << std::endl;
}
