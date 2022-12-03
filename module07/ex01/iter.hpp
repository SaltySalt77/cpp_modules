#ifndef	ITER_HPP
# define	ITER_HPP

# include <cstddef>
# include <iostream>
# include <iomanip>

template <typename T>
void iter(T	*arr, size_t len, void (*fptr)(T&)) {
		for (size_t i = 0; i < len; i++)
			fptr(arr[i]);
}

template <typename T>
void iter(const T	*arr, size_t len, void (*fptr)(const T&)) {
		for (size_t i = 0; i < len; i++)
			fptr(arr[i]);
}

template <typename T>
void	print(const T &a) {
	std::cout << a << std::endl;
}

template <typename T>
void	printTwice(T &a) {
	std::cout << std::setw(5) << a << " | " << std::setw(5) << a << std::endl;
}

template <typename T>
void	squareRoot(T &a) {
	a = a * a;
}

#endif