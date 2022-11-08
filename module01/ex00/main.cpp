#include "Zombie.hpp"
#include <iostream>

int	main() {
	Zombie	zombieOne;
	Zombie	zombieTwo("Mark");
	Zombie	*zombieThree = newZombie("Toros");
	std::cout << std::endl;
	zombieOne.announce();
	zombieTwo.announce();
	zombieThree->announce();
	randomChump("Armen");
	std::cout << std::endl;
	delete zombieThree;
	return 0;
}