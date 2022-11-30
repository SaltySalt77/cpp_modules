#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <string>

Base	*generate() {
	int ret;

	ret = rand() % 3;
	if (ret == 1)
		return dynamic_cast<Base *>(new A);
	else if (ret == 2)
		return dynamic_cast<Base *>(new B);
	else
		return dynamic_cast<Base *>(new C);
}

void	identify(Base	*p) {
	std::string	type;

	A	*aPtr = dynamic_cast<A *>(p);
	if (aPtr)
		type.append("Class A");
	B	*bPtr = dynamic_cast<B *>(p);
	if (bPtr)
		type.append("Class B");
	C	*cPtr = dynamic_cast<C *>(p);
	if (cPtr)
		type.append("Class C");
	if (type.size() == 7)
		std::cout << type << std::endl;
	else
		std::cout << "Class Base." << std::endl;
}

void identify(Base& p) {
	std::string type;

	try {
		A	&aPtr = dynamic_cast<A&>(p);
		(void) aPtr;
		type.append("Class A");
	}
	catch (...) {}
	try {
		B	&bPtr = dynamic_cast<B&>(p);
		(void) bPtr;
		type.append("Class B");
	}
	catch (...) {}
	try {
		C	&cPtr = dynamic_cast<C&>(p);
		(void) cPtr;
		type.append("Class C");
	}
	catch (...) {}
	if (type.size() == 7)
		std::cout << type << std::endl;
	else
		std::cout << "Class Base." << std::endl;
}

int	main() {
	srand(time(NULL));

	Base	*ptr = generate();
	Base	&ref = *ptr;

	identify(ptr);
	identify(ref);

	delete ptr;

	ptr = new Base;

	identify(ptr);

	delete ptr;

	return 0;
}