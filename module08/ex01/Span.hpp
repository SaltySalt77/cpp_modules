#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span {
private :
	std::vector<int>	vec;
public :
	Span();
	Span(const Span	&span);
	Span	&operator= (const Span	&span);
	~Span();

	void addNumber(int N);

	int	shortestSpan();
	int	longestSpan();

};

#endif