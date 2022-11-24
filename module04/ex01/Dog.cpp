#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
	type = "dog";
	std::cout << "Generating one dog. 🐕" << std::endl;
	brain = new Brain;
}

Dog::Dog(const Dog	&dog) : Animal() {
	this->type = dog.type;
	std::cout << "Creating dog copied version of 🐕" << type << std::endl;
	this->brain = new Brain;
	this->brain = dog.brain;
}

Dog	&Dog::operator=(const Dog	&dog) {
	if (this == &dog)
		return *this;
	this->type = dog.type;
	delete this->brain;
	this->brain = new Brain;
	this->brain = dog.brain;
	return *this;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog is disappearing for good. 🐕" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "🐶 WOOF WOOF 🐶" << std::endl;
}
