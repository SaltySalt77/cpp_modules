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

	bool	operator > (const Fixed	&compare);
	bool	operator < (const Fixed	&compare);
	bool	operator >= (const Fixed	&compare);
	bool	operator <= (const Fixed	&compare);
	bool	operator == (const Fixed	&compare);
	bool	operator != (const Fixed	&compare);

	Fixed	operator + (const Fixed	&fixed);
	Fixed	operator - (const Fixed	&fixed);
	Fixed	operator * (const Fixed	&fixed);
	Fixed	operator / (const Fixed	&fixed);

	const Fixed	&operator ++ ();
	const Fixed	operator  ++ (int);
	const Fixed	&operator -- ();
	const Fixed	operator  -- (int);

	static const Fixed	&min(const Fixed	&fixed1, const Fixed	&fixed2);
	static Fixed	&min(Fixed	&fixed1, Fixed	&fixed2);
	static const Fixed	&max(const Fixed	&fixed1, const Fixed	&fixed2);
	static Fixed	&max(Fixed	&fixed1, Fixed	&fixed2);

};

std::ostream& operator << (std::ostream	&out, const Fixed	&fixed);

#endif