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

		iter = container.begin();
		for (; iter != container.end(); iter++) {
			if (*iter == tofind)
				return iter;
		}
		throw NoOccurrenceFound();
}

#endif