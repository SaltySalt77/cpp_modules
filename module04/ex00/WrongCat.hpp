#ifndef	WRONGCAT_HPP
# define WRONGCAT_HPP

#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	WrongCat(const WrongCat	&cat);
	WrongCat	&operator=(const WrongCat	&wrongCat);
	~WrongCat();
	void	makeSound() const;
};

#endif