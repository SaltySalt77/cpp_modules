#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("Anonymous") {
	std::cout << "Generating " << name << " ClapTrap" << std::endl;
	hitPoint = 10;
	energyPoint = 10;
	attackDamage = 10;
}

ClapTrap::ClapTrap(std::string	name) : name(name) {
	std::cout << "Generating ClapTrap named "<< name << std::endl;
	hitPoint = 10;
	energyPoint = 10;
	attackDamage = 10;
}

ClapTrap::ClapTrap(const ClapTrap	&clapTrap) : name(clapTrap.name) {
	std::cout << "Creating copied version of ClapTrap named " << name << std::endl;
}

ClapTrap	&ClapTrap::operator= (const ClapTrap	&clapTrap) {
	std::cout << "Copying information of ClapTrap named " << clapTrap.name << std::endl;
	this->name = clapTrap.name;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << name << " disappeared for good" << std::endl;
}

bool	ClapTrap::canAct() {
	if (energyPoint > 0 && hitPoint > 0)
		return true;
	else if (hitPoint <= 0)
		std::cout << "ClapTrap " << name << " is completely broken.";
	else if (energyPoint <= 0)
		std::cout << "ClapTrap " << name << " has no energy points left.";
	std::cout << " It stands still and silent, doing nothing." << std::endl;
	return false;
}

void	ClapTrap::attack(const std::string	&target) {
	if (canAct()) {
		std::cout << "ClapTrap "<< name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoint--;
	}
}

void	ClapTrap::takeDamage(unsigned int	amount) {
		std::cout << name << " took " << amount << "points of damage" << std::endl;
		hitPoint -= amount;
		if (hitPoint < 0)
			hitPoint = 0;
}

void	ClapTrap::beRepaired(unsigned int	amount) {
	if (canAct()) {
		std::cout << name << " is repairing itself for " << amount << "points!" << std::endl;
		hitPoint += amount;
		if (hitPoint > 10)
			hitPoint = 10;
		energyPoint--;
	}
}