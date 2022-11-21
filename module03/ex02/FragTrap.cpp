#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "Creating anonymouse FragTrap" << std::endl;
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const std::string	&name) : ClapTrap(name) {
	std::cout << "Creating FragTrap named " << name << std::endl;
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap	&fragTrap) : ClapTrap(fragTrap.name) {
	std::cout << "Copying FragTrap named " << name << std::endl;
	this->hitPoint = fragTrap.hitPoint;
	this->energyPoint = fragTrap.energyPoint;
	this->attackDamage = fragTrap.attackDamage;
}

FragTrap	&FragTrap::operator= (const FragTrap	&fragTrap) {
	std::cout << "Copying information of FragTrap named " << fragTrap.name << std::endl;
	if (this == &fragTrap)
		return *this;
	this->name = fragTrap.name;
	this->hitPoint = fragTrap.hitPoint;
	this->energyPoint = fragTrap.energyPoint;
	this->attackDamage = fragTrap.attackDamage;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap named " << name << " disappeared for good" << std::endl;
}

void	FragTrap::hiFiveGuys() {
	std::cout << name << " puts it's hand up high in the air" << std::endl;
	std::cout << "* HIGH FIVE GUYS *" << std::endl;
}