#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
	ClapTrap	clapTrap("clapTrap");
	std::cout << std::endl;
	ScavTrap	scavTrap("scavTrap");
	std::cout << std::endl;
	FragTrap	anonymous;
	std::cout << std::endl;
	FragTrap	anonymousCopy(anonymous);
	std::cout << std::endl;
	FragTrap	buzz("buzz");
	std::cout << std::endl;
	FragTrap	buzzCopy;

	buzzCopy = buzz;
	std::cout << std::endl;

	std::cout << "=========================================" << std::endl << std::endl;
	std::cout << "Generating enemies" << std::endl << std::endl;

	ClapTrap	enemy_1("enemy_1");
	std::cout << std::endl;
	ScavTrap	enemy_2("enemy_2");
	std::cout << std::endl;
	FragTrap	enemy_3("enemy_3");
	std::cout << std::endl;

	std::cout << "=========================================" << std::endl << std::endl;
	std::cout << "Testing skills" << std::endl << std::endl;

	clapTrap.attack("enemy_1");
	enemy_1.takeDamage(0);

	std::cout << std::endl;

	scavTrap.attack("enemy_2");
	enemy_2.takeDamage(20);

	std::cout << std::endl;

	buzz.attack("enemy_3");
	enemy_3.takeDamage(30);

	std::cout << std::endl;

	buzz.hiFiveGuys();

	std::cout << std::endl;
	std::cout << "=========================================" << std::endl << std::endl;
	return 0;
}
