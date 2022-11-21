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

	return 0;
}
