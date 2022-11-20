#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
private:
	int					rawBits;
	static const int	fractionalBits = 8;
public:
	Fixed();
	Fixed(const int		num);
	Fixed(const float	num);
	Fixed(const Fixed	&fixed);
	Fixed &operator= (const Fixed	&fixed);
	~Fixed();
	int		getRawBits() const;
	void	setRawBits(int const	raw);
	int		toInt() const;
	float	toFloat() const;
};

std::ostream& operator << (std::ostream	&out, const Fixed	&fixed);

#endif