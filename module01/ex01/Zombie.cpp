#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
	name = "Anonymous zombie";
	std::cout << "Generating " << name << std::endl;
}

Zombie::Zombie(std::string	name) {
	this->name = name;
	std::cout << "Generating zombie named " << name << std::endl;
}

Zombie::~Zombie() {
	std::cout << name << " disappeared for good" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string	name) {
	std::cout << "Setting zombie named " << this->name << " to " << name << "." << std::endl;
	this->name = name;
}