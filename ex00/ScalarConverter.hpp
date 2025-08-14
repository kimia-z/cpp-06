#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
public:
	ScalarConverter();
	~ScalarConverter();
	//ScalarConverter(const ScalarConverter &src);
	//ScalarConverter &operator=(const ScalarConverter &src);

	static void	convert(const std::string &literal);
};




#endif