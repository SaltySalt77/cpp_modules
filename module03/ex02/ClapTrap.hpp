#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap {
protected :
	std::string	name;
	int			hitPoint;
	int			energyPoint;
	int			attackDamage;
public:
	ClapTrap();
	ClapTrap(std::string	name);
	ClapTrap(const ClapTrap	&clapTrap);
	ClapTrap	&operator=(const ClapTrap	&ClapTrap);
	virtual ~ClapTrap();

	virtual void	attack(const std::string	&target);
	void	takeDamage(unsigned int	amount);
	void	beRepaired(unsigned int	amount);

	bool	canAct();
};

#endif