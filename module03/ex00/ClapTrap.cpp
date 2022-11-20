#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("Anonymous") {
	std::cout << "Generating " << name << " ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(std::string	name) : name(name) {
	std::cout << "Generating ClapTrap named "<< name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap	&clapTrap) : name(clapTrap.name) {
	std::cout << "Creating copied version of ClapTrap named " << name << std::endl;
}

ClapTrap	&ClapTrap::operator= (const ClapTrap	&clapTrap) {
	std::cout << "Copying information of ClapTrap named " << clapTrap.name << std::endl;
	this->name = clapTrap.name;
}

ClapTrap::~ClapTrap() {
	std::cout << name << " disappeared for good" << std::endl;
}

void	ClapTrap::attack(const std::string	&target) {
	std::cout << "ClapTrap "<< name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoint--;
}

void	ClapTrap::takeDamage(unsigned int	amount) {
	std::cout << "ClapTrap " << name << " took " << amount << "points of damage" << std::endl;
	energyPoint--;
	hitPoint -= amount;
}

void	ClapTrap::beRepaired(unsigned int	amount) {
	std::cout << "ClapTrap " << name << " is repairing itself for " << amount << "points!" << std::endl;
	energyPoint--;
	hitPoint += amount;
}

