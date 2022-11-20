#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap {
private :
	std::string	name;
	int			hitPoint = 10;
	int			energyPoint = 10;
	int			attackDamage = 0;
public:
	ClapTrap();
	ClapTrap(std::string	name);
	ClapTrap(const ClapTrap	&clapTrap);
	ClapTrap	&operator=(const ClapTrap	&ClapTrap);
	~ClapTrap();

	void	attack(const std::string	&target);
	void	takeDamage(unsigned int	amount);
	void	beRepaired(unsigned int	amount);
};

#endif