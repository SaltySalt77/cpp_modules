#include "WrongDog.hpp"
#include <iostream>

WrongDog::WrongDog() {
	type = "dog";
	std::cout << "Generating one dog. 🐕" << std::endl;
}

WrongDog::WrongDog(const WrongDog	&wrongDog) {
	this->type = wrongDog.type;
	std::cout << "Creating dog copied version of 🐕" << type << std::endl;
}

WrongDog	&WrongDog::operator=(const WrongDog	&wrongDog) {
	if (this == &wrongDog)
		return *this;
	this->type = wrongDog.type;
	return *this;
}

WrongDog::~WrongDog() {
	std::cout << "WrongDog is disappearing for good. 🐕" << std::endl;
}

void	WrongDog::makeSound() const {
	std::cout << "🐶 WOOF WOOF 🐶" << std::endl;
}
