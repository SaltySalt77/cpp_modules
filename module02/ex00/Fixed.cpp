#include "Fixed.hpp"


Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	rawBits = 0;
}

Fixed::Fixed(const Fixed	&fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed	&Fixed::operator= (const Fixed	&fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->rawBits = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits;
}

void	Fixed::setRawBits(int const	raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->rawBits = raw;
}
