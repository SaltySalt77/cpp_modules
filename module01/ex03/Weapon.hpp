#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon {
private :
	std::string	type;
public :
	Weapon();
	Weapon(std::string	weaponType);
	void	setType(std::string	newType);
	const std::string &getType();
};

#endif