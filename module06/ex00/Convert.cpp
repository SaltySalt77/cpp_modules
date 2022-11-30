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

void	Convert::convertValue() {

	if (!origin.compare("nanf") || !origin.compare("nan")) {
		isNAN = true;
		_float = static_cast<float>(NAN);
		_double = static_cast<double>(NAN);
	}
	else if (!origin.compare("inff") || !origin.compare("-inff") || !origin.compare("+inff")
		|| !origin.compare("inf") || !origin.compare("-inf") || !origin.compare("+inf") ) {
			isINF = true;
			if (origin[0] == '-') {
				_double = static_cast<double>(INFINITY * (-1));
				_float = static_cast<float>(INFINITY * (-1));
			}
			else {
				_double = static_cast<double>(INFINITY);
				_float = static_cast<float>(INFINITY);
			}
	}
	else if (origin.size() == 1) {
		_char = static_cast<char>(origin[0]);
		if (isdigit(_char))
			_char -= 48;
		_int = static_cast<int>(_char);
		_float = static_cast<float>(_char);
		_double = static_cast<double>(_char);
	}
	else if (origin.find('.') != std::string::npos) {
		char *ptr;
		long long tmp = strtoll(origin.c_str(), &ptr, 10);
		if (tmp > INT_MAX || tmp < INT_MIN)
			isImpossible = true;
		_double = atof(origin.c_str());
		_float = static_cast<float>(_double);
		_int = static_cast<int>(_double);
		_char = static_cast<char>(_double);
		printDot = false;
	}
	else {
		char *ptr;
		long long tmp = strtoll(origin.c_str(), &ptr, 10);
		if (tmp > INT_MAX || tmp < INT_MIN)
			isImpossible = true;
		_int = atoi(origin.c_str());
		_char = static_cast<char>(_int);
		_float = static_cast<float>(_int);
		_double = static_cast<double>(_int);
	}
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