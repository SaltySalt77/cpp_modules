#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <string>
#include <climits>
#include <cctype>

class Convert {
private :
	bool		isNAN;
	bool		isINF;
	bool		isImpossible;
	bool		printDot;
	char		_char;
	int			_int;
	float		_float;
	double		_double;
	std::string	origin;
public :
	Convert();
	Convert(char	*origin);
	Convert(const Convert	&convert);
	Convert	&operator=(const Convert	&Convert);
	~Convert();

	void	convertValue();

	void	printChar();
	void	printInt();
	void	printFloat();
	void	printDouble();
};


#endif