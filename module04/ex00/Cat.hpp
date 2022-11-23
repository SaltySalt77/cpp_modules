#ifndef	CAT_HPP
# define CAT_HPP 

#include <string>
#include "Animal.hpp"

class Cat : public Animal {
public:
	void	makeSound() const;
};

#endif