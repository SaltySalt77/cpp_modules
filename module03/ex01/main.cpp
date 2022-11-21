#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
	ClapTrap	clapTrap("clapTrap");
	std::cout << std::endl;
	ScavTrap	anonymous;
	std::cout << std::endl;
	ScavTrap	buzz("buzz");
	std::cout << std::endl;
	ScavTrap	anonymousCopy(anonymous);
	std::cout << std::endl;
	ScavTrap	buzzCopy;
	buzzCopy = buzz;
	std::cout << std::endl;

	std::cout << "=========================================" << std::endl << std::endl;
	std::cout << "Generating enemies" << std::endl << std::endl;

	ClapTrap	enemy_1("enemy_1");
	std::cout << std::endl;
	ScavTrap	enemy_2("enemy_2");
	std::cout << std::endl;

	std::cout << "=========================================" << std::endl << std::endl;
	std::cout << "Testing skills" << std::endl << std::endl;

	clapTrap.attack("enemy_1");
	enemy_1.takeDamage(0);

	std::cout << std::endl;

	anonymous.attack("enemy_2");
	enemy_2.takeDamage(20);

	std::cout << std::endl;

	buzz.guardGate();

	std::cout << std::endl;

	buzz.guardGate();

	std::cout << std::endl;
	std::cout << "=========================================" << std::endl << std::endl;
	return 0;
}
