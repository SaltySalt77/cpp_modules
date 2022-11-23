#ifndef	DOG_HPP
# define DOG_HPP 

#include <string>
#include "Animal.hpp"

class Dog : public Animal {
public:
	void	makeSound() const;
};

#endif