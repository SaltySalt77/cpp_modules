#include "Fixed.hpp"


Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	rawBits = 0;
}

Fixed::Fixed(const int	num) {
	std::cout << "Int constructor called" << std::endl;
	rawBits = num << this->fractionalBits;
}

Fixed::Fixed(const float	num) {
	std::cout << "Float constructor called" << std::endl;
	rawBits = (int) roundf(num * (1 << this->fractionalBits));
}

Fixed::Fixed(const Fixed	&fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed	&Fixed::operator= (const Fixed	&fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits = fixed.rawBits;
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

int	Fixed::toInt() const {
	return this->rawBits >> this->fractionalBits;
}

float	Fixed::toFloat() const {
	return (float) this->rawBits / (1 << this->fractionalBits);
}

std::ostream &operator<<(std::ostream	&out, const Fixed	&fixed) {
	out << fixed.toFloat();
	return out;
}