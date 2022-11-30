#include "Convert.hpp"
#include <cmath>
#include <cstdlib>
#include <sstream>

Convert::Convert() {
	isNAN = false;
	isINF = false;
	isImpossible = false;
	printDot = true;
}

Convert::Convert(char	*origin) {
	this->origin = origin;
	isNAN = false;
	isINF = false;
	isImpossible = false;
	printDot = true;
}

Convert::Convert(const Convert	&convert) {
	origin = convert.origin;
	isNAN = convert.isNAN;
	_char = convert._char;
	_int = convert._int;
	_float = convert._float;
	_double = convert._double;
	isINF = convert.isINF;
	isImpossible = convert.isImpossible;
	printDot = convert.printDot;
}

Convert	&Convert::operator=(const Convert	&convert) {
	if (this == &convert)
		return *this;
	origin = convert.origin;
	isNAN = convert.isNAN;
	_char = convert._char;
	_int = convert._int;
	_float = convert._float;
	isINF = convert.isINF;
	isImpossible = convert.isImpossible;
	printDot = convert.printDot;
	return *this;
}

Convert::~Convert() {
}

void	Convert::convertChar() {
	if (origin.size() == 1) {
		_char = static_cast<char>(atoi(origin.c_str()));
		if (isdigit(_char))
			_char -= 48;
	}
	else {
		_char = static_cast<char>(atoi(origin.c_str()));
	}
}


void	Convert::convertValue() {

}

void	Convert::printChar() {
	std::cout << "char : ";
	if (isNAN || isINF || _int > CHAR_MAX || _int < CHAR_MIN || isImpossible)
		std::cout << "impossible" << std::endl;
	else if (!isprint(_char))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << _char << std::endl;
}

void	Convert::printInt() {
	std::cout << "Int : ";
	if (isNAN || isINF || isImpossible)
		std::cout << "impossible" << std::endl;
	else
		std::cout << _int << std::endl;
}

void	Convert::printFloat() {
	std::cout << "Float : ";
	if (isImpossible) {
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << _float;
	if (_float == static_cast<float>(_int))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void	Convert::printDouble() {
	std::cout << "Double : ";
	if (isImpossible) {
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << _double;
	if (_double == static_cast<double>(_int))
		std::cout << ".0" << std::endl;
}