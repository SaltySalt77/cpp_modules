#include "Fixed.hpp"


Fixed::Fixed() {
	rawBits = 0;
}

Fixed::Fixed(const int	num) {
	rawBits = num << this->fractionalBits;
}

Fixed::Fixed(const float	num) {
	rawBits = (int) roundf(num * (1 << this->fractionalBits));
}

Fixed::Fixed(const Fixed	&fixed) {
	*this = fixed;
}

Fixed	&Fixed::operator= (const Fixed	&fixed) {
	this->rawBits = fixed.rawBits;
	return *this;
}

Fixed::~Fixed() {
}

int	Fixed::getRawBits() const {
	return this->rawBits;
}

void	Fixed::setRawBits(int const	raw) {
	this->rawBits = raw;
}

int	Fixed::toInt() const {
	return this->getRawBits() >> this->fractionalBits;
}

float	Fixed::toFloat() const {
	return (float) this->getRawBits() / (1 << this->fractionalBits);
}

std::ostream &operator<< (std::ostream	&out, const Fixed	&fixed) {
	out << fixed.toFloat();
	return out;
}

bool	Fixed::operator> (const Fixed	&compare) {
	return this->getRawBits() > compare.getRawBits();
}

bool	Fixed::operator< (const Fixed	&compare) {
	return this->getRawBits() < compare.getRawBits();
}

bool	Fixed::operator>= (const Fixed	&compare) {
	return this->getRawBits() >= compare.getRawBits();
}

bool	Fixed::operator<= (const Fixed	&compare) {
	return this->getRawBits() <= compare.getRawBits();
}

bool	Fixed::operator== (const Fixed	&compare) {
	return this->getRawBits() == compare.getRawBits();
}

bool	Fixed::operator!= (const Fixed	&compare) {
	return this->getRawBits() != compare.getRawBits();
}

Fixed	Fixed::operator+ (const Fixed	&fixed) {
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator- (const Fixed	&fixed) {
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator* (const Fixed	&fixed) {
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/ (const Fixed	&fixed) {
	return Fixed(this->toFloat() / fixed.toFloat());
}

const Fixed	&Fixed::operator++ () {
	++(this->rawBits);
	return *this;
}

const Fixed	Fixed::operator++ (int) {
	Fixed	ret(*this);

	this->rawBits++;
	return ret;
}

const Fixed	&Fixed::operator-- () {
	--(this->rawBits);
	return *this;
}

const Fixed	Fixed::operator-- (int) {
	Fixed	ret(*this);

	this->rawBits--;
	return ret;
}

const Fixed	&Fixed::min(const Fixed	&fixed1, const Fixed	&fixed2) {
	if ((Fixed) fixed1 < (Fixed) fixed2)
		return fixed1;
	return fixed2;
}

Fixed	&Fixed::min(Fixed	&fixed1, Fixed	&fixed2) {
	if (fixed1 < fixed2)
		return fixed1;
	return fixed2;
}

const Fixed	&Fixed::max(const Fixed	&fixed1, const Fixed	&fixed2) {
	if ((Fixed) fixed1 > (Fixed) fixed2)
		return fixed1;
	return fixed2;
}

Fixed	&Fixed::max(Fixed	&fixed1, Fixed	&fixed2) {
	if (fixed1 > fixed2)
		return fixed1;
	return fixed2;
}