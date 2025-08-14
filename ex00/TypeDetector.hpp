#ifndef TYPEDETECTOR_HPP
#define TYPEDETECTOR_HPP

#include <iostream>
#include <string>

enum type {T_CHAR, T_INT, T_FLOAT, T_DOUBLE, T_INVALID};


class TypeDetector
{
public:
	TypeDetector();
	~TypeDetector();
	//TypeDetector(const TypeDetector &src);
	//TypeDetector &operator=(const TypeDetector &src);

	static bool	isChar(const std::string &literal);
	static bool	isInt(const std::string &literal);
	static bool	isFloat(const std::string &literal);
	static bool	isDouble(const std::string &literal);
	static bool	isSpecialFloat(const std::string &literal);
	static bool	isSpecialDouble(const std::string &literal);
	static bool	isDisplayable(char c);
	static type	getType(const std::string &literal);

};

#endif