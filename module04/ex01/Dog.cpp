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
	for (int i = 0; i < 100; i++) {
		std::string	tmp = dog.getBrain().getIdea(i);
		if (!tmp.size())
			break ;
		this->brain->addIdea(tmp);
	}
}

Dog	&Dog::operator=(const Dog	&dog) {
	if (this == &dog)
		return *this;
	this->type = dog.type;
	delete this->brain;
	this->brain = new Brain;
	for (int i = 0; i < 100; i++) {
		std::string	tmp = dog.getBrain().getIdea(i);
		if (!tmp.size())
			break ;
		this->brain->addIdea(tmp);
	}
	return *this;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog is disappearing for good. 🐕" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "🐶 WOOF WOOF 🐶" << std::endl;
}

Brain	&Dog::getBrain() const {
	return *this->brain;
}