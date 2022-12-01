#ifndef	ITER_HPP
# define	ITER_HPP

# include <cstddef>
# include <iostream>

template <typename T>
void iter(T	*arr, size_t len, void (*fptr)(T)) {
		for (size_t i = 0; i < len; i++)
			fptr(arr[i]);
}

template <typename T>
void	print(T a) {
	std::cout << a << std::endl;
}

#endif