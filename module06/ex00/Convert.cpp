#include "Convert.hpp"
#include <cmath>
#include <climits>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <iostream>

Convert::Convert() {
	isNAN = false;
	isINF = false;
	isImpossible = false;
}

Convert::Convert(char	*origin) {
	this->origin = origin;
	isNAN = false;
	isINF = false;
	isImpossible = false;
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
	return *this;
}

Convert::~Convert() {
}

void	Convert::convertChar() {
	if (origin.size() == 1) {
		_char = static_cast<char>(origin[0]);
		if (isdigit(_char))
			_char -= 48;
	}
	else if ((origin[0] == '-' || origin[0] == '+') && isdigit(origin[1]) && origin.size() == 2) {
		_char = static_cast<char>(atoi(origin.c_str()));
		_char -= 48;
	}
	else {
		_char = static_cast<char>(atoi(origin.c_str()));
	}
}

void	Convert::convertInt() {
	std::stringstream	ss;
	std::string			tmp;

	_int = static_cast<int>(atoi(origin.c_str()));
	if (_int == INT_MIN) {
		ss << _int;
		tmp = ss.str();
		if (tmp.compare(origin.substr(0, 11)))
			isImpossible = true;
	}
	else if (_int == 0 && ((!((origin[0] == '-' || origin[0] == '+') && origin[1] == 0)) && !origin[0]))
		isImpossible = true;
}

void	Convert::convertFloat() {
	_float = static_cast<float>(_double);
	if (!isINF && _float == INFINITY) {
		isINF = true;
		_double = static_cast<double>(INFINITY);
	}
}

void	Convert::convertDouble() {
	if (!origin.compare("nanf") || !origin.compare("nan")) {
		isNAN = true;
		_double = static_cast<double>(NAN);
	}
	else if (!origin.compare("inff") || !origin.compare("-inff") || !origin.compare("+inff")
			|| !origin.compare("inf") || !origin.compare("-inf") || !origin.compare("+inf")) {
		isINF = true;
		if (origin[0] == '-') {
			_double = static_cast<double>(INFINITY * (-1));
		}
		else {
			_double = static_cast<double>(INFINITY);
		}
	}
	else if (isImpossible){
		return ;
	}
	else {
		_double = static_cast<double>(atof(origin.c_str()));
	}
}

void	Convert::convertValue() {
	convertChar();
	convertInt();
	convertDouble();
	convertFloat();
	if (isNAN || isINF)
		return ;
	if (origin.size() != 1 && !isdigit(origin[0])) {
		if (origin[0] != '+' && origin[0] != '-') {
			isImpossible = true;
		}
		else if (!isdigit(origin[1])) {
			isImpossible = true;
		}
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
	if (origin.size() == 1 && !isdigit(origin[0]) && isprint(_char))
		isImpossible = true;

}

void	Convert::printInt() {
	std::cout << "Int : ";
	if (isNAN || isINF || isImpossible)
		std::cout << "impossible" << std::endl;
	else
		std::cout << _int << std::endl;
}

void	Convert::printFloat() {
	std::stringstream	ss;
	std::string			tmp;

	if (_int >= 0)
		ss << _int;
	else
		ss << _int * -1;
	tmp = ss.str();
	std::cout << "Float : ";
	if (isImpossible && !isINF && !isNAN) {
		std::cout << "impossible" << std::endl;
		return ;
	}
	else if (isINF || isNAN)
		std::cout << _float;
	else
		std::cout << std::showpoint << std::setprecision(tmp.size() + 1) << _float;
	std::cout << "f" << std::endl;
}

void	Convert::printDouble() {
	std::cout << "Double : ";
	if (isImpossible && !isINF && !isNAN) {
		std::cout << "impossible" << std::endl;
		return ;
	}
	else
		std::cout << _double << std::endl;
}