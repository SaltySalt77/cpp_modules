#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain {
private :
	std::string ideas[100];
	int			count;
	bool		isFull;
public :
	Brain();
	Brain(const Brain	&brain);
	Brain	&operator= (const Brain	&brain);
	~Brain();

	std::string	getIdea(int	index) const;
	void	addIdea(const std::string	idea);
	void	removeIdea();
};

#endif