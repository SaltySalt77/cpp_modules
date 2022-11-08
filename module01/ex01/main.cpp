#include "Zombie.hpp"
#include <iostream>

int	main() {
	Zombie	*zombies;

	zombies = zombieHorde(3, "Hourig");

	int	i = 0;
	while (i < 3)
		zombies[i++].announce();

	delete [] zombies;
	return 0;
}