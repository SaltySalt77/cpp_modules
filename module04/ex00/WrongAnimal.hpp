#ifndef	WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
protected:
	std::string	type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal	&wrongAnimal);
	WrongAnimal	&operator= (const WrongAnimal	&wrongAnimal);
	~WrongAnimal();

	std::string	getType() const;
	void		setType(std::string	type);
	void	makeSound() const;
};

#endif