#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

class NoOccurrenceFound : public std::exception {
public :
	const char * what() const throw() ;
};

template <typename	T>
typename T::iterator easyfind(T &container, int tofind) {
	typename T::iterator iter;

	iter = std::find(container.begin(), container.end(), tofind);
	if (iter == container.end())
		throw NoOccurrenceFound();
	return iter;
}

#endif