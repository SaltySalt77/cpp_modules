#include "Data.hpp"
#include <iostream>

uintptr_t	serialize(Data	*ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*deserialize(uintptr_t	raw) {
	return reinterpret_cast<Data *>(raw);
}

int	main(int argc, char	**argv) {
	Data		*dptr = new Data;
	Data		var;
	Data		&dRef = var;
	uintptr_t	raw;

	if (argc != 2)
		dptr->str = "cat";
	else
		dptr->str = argv[1];
	var.str = dptr->str;

	// 포인터 변수
	std::cout << "dptr->str    : " << dptr->str << std::endl;

	raw = serialize(dptr);

	std::cout << "serialized   : " << raw << std::endl;

	Data	*newData = deserialize(raw);

	std::cout << "deserialized : " << newData->str << std::endl << std::endl;

	delete dptr;


	// 기본 변수
	std::cout << "var.str      : " << var.str << std::endl;

	raw = serialize(&var);

	std::cout << "serialized   : " << raw << std::endl;

	newData = deserialize(raw);

	std::cout << "deserialized : " << newData->str << std::endl << std::endl;


	// 레퍼런스 변수
	std::cout << "dRef.str     : " << dRef.str << std::endl;

	raw = serialize(&dRef);

	std::cout << "serialized   : " << raw << std::endl;

	newData = deserialize(raw);

	std::cout << "deserialized : " << newData->str << std::endl;


	return 0;
}