#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() {};
	MutantStack(const MutantStack	&mutantStack);
	MutantStack	&operator=(const MutantStack	&mutantStack);
	~MutantStack() {};

	typedef typename MutantStack<T>::stack::container_type::iterator	iterator;
	iterator	begin() { return this->c.begin(); };
	iterator	end() { return this->c.end(); };

	typedef typename MutantStack<T>::stack::container_type::reverse_iterator	reverse_iterator;
	reverse_iterator	rbegin() { return this->c.rbegin(); };
	reverse_iterator	rend() { return this->c.rend(); };

	typedef typename MutantStack<T>::stack::container_type::const_iterator	const_iterator;
	const_iterator	cbegin() { return this->c.cbegin();};
	const_iterator	cend() { return this->c.cend(); };

	typedef typename MutantStack<T>::stack::container_type::reverse_iterator	const_reverse_iterator;
	const_reverse_iterator	crbegin() { return this->c.crbigin(); };
	const_reverse_iterator crend() { return this->c.crend(); };
};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack	&mutantStack) {
	this->c = mutantStack.c;
}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack	&mutantStack) {
	if (this != &mutantStack)
		this->c = mutantStack.c;
	return *this;
}

#endif