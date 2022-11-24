#ifndef	WRONGDOG_HPP
# define WRONGDOG_HPP

#include <string>
#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
public:
	WrongDog();
	WrongDog(const WrongDog	&wrongDog);
	WrongDog	&operator=(const WrongDog	&wrongDog);
	~WrongDog();
	void	makeSound() const;
};

#endif