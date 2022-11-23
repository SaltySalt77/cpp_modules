#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
	name = "Anonymous";
	std::cout << "Creating Anonymous ScavTrap." << std::endl;
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(std::string	name) : ClapTrap() {
	this->name = name;
	std::cout << "Creating ScavTrap named " << name << std::endl;
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap	&scavTrap) : ClapTrap() {
	this->name = name;
	std::cout << "Creating copied version of ScavTrap named " << name << std::endl;
	this->hitPoint = scavTrap.hitPoint;
	this->energyPoint = scavTrap.energyPoint;
	this->attackDamage = scavTrap.attackDamage;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap	&scavTrap) {
	std::cout << "Copying information of ScavTrap named " << scavTrap.name << std::endl;
	if (this == &scavTrap)
		return *this;
	this->name = scavTrap.name;
	this->hitPoint = scavTrap.hitPoint;
	this->energyPoint = scavTrap.energyPoint;
	this->attackDamage = scavTrap.attackDamage;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap named " << name << " disappeared for good" << std::endl;
}

void	ScavTrap::attack(const std::string	&target) {
	if (canAct()) {
		std::cout << "ScavTrap "<< name << " attacks " << target << ", causing " << attackDamage << " points of damage!!!!!!!!" << std::endl;
		energyPoint--;
	}
}

void	ScavTrap::guardGate() {
	static bool modSwitch = false;

	if (!canAct())
		return ;
	if (modSwitch) {
		std::cout << "ScavTrap " << name << " turns off the gate keeper mode" << std::endl;
		energyPoint--;
		modSwitch = false;
	}
	else {
		std::cout << "ScavTrap " << name << " is now on gate keeper mode" << std::endl;
		energyPoint--;
		modSwitch = true;
	}
}