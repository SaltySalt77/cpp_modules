#ifndef	ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {
private :
	unsigned int	len;
	T				*arr;
public :
	Array();
	Array(unsigned int	len);
	Array(const Array	&array);
	Array	&operator=(const Array	&arr);
	~Array();

	T	&operator[] (unsigned int	idx);
	const T	&operator[] (unsigned int	idx) const;

	class OutOfRangeException : public std::exception {
	public :
		const char * what() const throw();
	};

	unsigned int	size();
};

template <typename T>
Array<T>::Array() {
	len = 1;
	arr = new T[1];
}

template <typename T>
Array<T>::Array(unsigned int	len) {
	this->len = len;
	arr = new T[len];
}

template <typename T>
Array<T>::Array(const Array	&array) {
	this->len = array.len;
	this->arr = new T[this->len];
	for (unsigned int i = 0; i < array.len; i++) {
		arr[i] = array.arr[i];
	}
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array	&array) {
	if (this == &array)
		return *this;
	delete [] this->arr;
	this->len = array.len;
	this->arr = new T[this->len];
	for (int i = 0; i < array.len; i++) {
		arr[i] = array.arr[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array<T>() {
	delete [] arr;
}

template <typename T>
T	&Array<T>::operator[] (unsigned int idx) {
	if (idx >= len || idx < 0)
		throw OutOfRangeException();
	return arr[idx];
}

template <typename T>
const T	&Array<T>::operator[] (unsigned int idx) const {
	if (idx >= len || idx < 0)
		throw OutOfRangeException();
	return arr[idx];
}

template <typename T>
const char	*Array<T>::OutOfRangeException::what() const throw() {
	return "Index OUT OF RANGE\n";
}

template <typename T>
unsigned int	Array<T>::size() {
	return len;
}

// #include "Array.hpp"
#endif