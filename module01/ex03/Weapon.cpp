#include "Weapon.hpp"

Weapon::Weapon() {
	type = "none";
}

Weapon::Weapon(std::string	type) {
	this->type = type;
}

void	Weapon::setType(std::string	newType) {
	type = newType;
}

const std::string	&Weapon::getType() {
	return type;
}
