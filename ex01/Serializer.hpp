#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Data.hpp"


class Serializer
{
public:
	Serializer();
	~Serializer();
	Serializer(const Serializer &src);
	Serializer &operator=(const Serializer &src);

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

};



#endif