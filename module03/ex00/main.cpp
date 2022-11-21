#include "ClapTrap.hpp"
#include <iostream>

int main() {
	ClapTrap	anonymous;
	ClapTrap	anonymousCopy;
	ClapTrap	buzz("buzz");
	ClapTrap	buzzCopy(buzz);

	std::cout << std::endl;

	anonymousCopy = anonymous;

	std::cout << std::endl;

	std::cout << "Generating enemies." << std::endl;

	std::cout << std::endl;

	ClapTrap	enemy_1("enemy_1");
	ClapTrap	enemy_2("enemy_2");

	std::cout << std::endl;

	enemy_1.attack("buzz");
	buzz.takeDamage(0);

	std::cout << std::endl;

	buzz.beRepaired(10);

	std::cout << std::endl;

	std::cout << "Test energy point." << std::endl;

	std::cout << std::endl;

	int i = 0;
	while (i++ < 10){
		buzz.attack("enemy_1");
		if (i != 10)
			enemy_1.takeDamage(0);
	}

	std::cout << std::endl;

	std::cout << "Test hit point(a.k.a. health point)" << std::endl;

	std::cout << std::endl;

	i = 0;
	while (i++ < 10)
		anonymous.takeDamage(1);

	std::cout << std::endl;

	anonymous.beRepaired(10);

	std::cout << std::endl;

	return 0;
}