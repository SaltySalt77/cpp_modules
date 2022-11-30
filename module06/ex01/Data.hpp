#ifndef DATA_HPP
# define DATA_HPP

#include <string>

typedef struct s_data {
	std::string	str;
} Data;

uintptr_t	serialize(Data	*ptr);

Data	*deserialize(uintptr_t raw);

#endif