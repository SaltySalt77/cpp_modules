#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template <typename	T>
typename T::iterator easyfind(T &container, int tofind) {
	T<int>::iterator iter;

	iter = container.begin();
	for (; iter != &(container.end()) ; iter++) {
		if (*iter == tofind)
			return iter;
	}
	throw /* 예외처리 */
}

#endif