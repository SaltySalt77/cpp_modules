#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>

class Span {
private :
	std::vector<int>	vec;
	unsigned int					maxSize;
public :
	Span();
	Span(unsigned int N);
	Span(const Span	&span);
	Span	&operator= (const Span	&span);
	~Span();

	void	addNumber(int N);
	void	addNumber(int min, int max);
	void	addNumber(int	*arr, unsigned int size);

	long long	shortestSpan();
	long long	longestSpan();

};

#endif