#include "TypeDetector.hpp"

const std::string specialFloat[] = {"-inff", "+inff", "nanf"}; //-inff, +inff, and nanf.
const std::string specialDouble[] = {"-inf", "+inf", "nan"}; //-inf, +inf, and nan.

TypeDetector::TypeDetector()
{}
TypeDetector::~TypeDetector()
{}
// TypeDetector::TypeDetector(const TypeDetector &src)
// {}
// TypeDetector &TypeDetector::operator=(const TypeDetector &src)
// {}

bool	TypeDetector::isDisplayable(char c)
{
	return (c >= 32 && c <= 126);
}


bool	TypeDetector::isChar(const std::string &literal)
{
	return (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]));
}
bool	TypeDetector::isInt(const std::string &literal)
{
	int i = 0;
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	if (i >= (int)literal.length())
		return false;
	while (literal[i])
	{
		if (!isdigit(literal[i]))
			return (false);
		i++;
	}
	try{
		std::stoi(literal);
	}
	catch (std::invalid_argument const& e){
		std::cout << "integer std::invalid_argument::what(): " << e.what() << '\n';
		return (false);
	}
	catch (std::out_of_range const& e){
		std::cout << "integer std::out_of_range::what(): " << e.what() << '\n';
		return (false);
	}
	return (true);
}
bool	TypeDetector::isFloat(const std::string &literal)
{
	if (literal.length() < 2 || literal.back() != 'f') return (false);
	std::string core = literal.substr(0, literal.length() - 1); // without f at the end
	int i = 0;
	if (core[i] == '-' || core[i] == '+')
		i++;
	if (i >= (int)core.length()) return false;
	bool isDot = false;
	while (core[i])
	{
		if (core[i] == '.'){
			if (isDot) return (false);
			isDot = true;
		}
		else if (!isdigit(core[i])) return (false);
		i++;
	}
	if (isDot == false) return (false);
	try{
		std::stof(core);
	} catch (std::invalid_argument const& e){
		std::cout << "float std::invalid_argument::what(): " << e.what() << '\n';
		return (false);
	} catch (std::out_of_range const& e){
		std::cout << "float std::out_of_range::what(): " << e.what() << '\n';
		return (false);
	}
	return (true);
}
bool	TypeDetector::isDouble(const std::string &literal)
{
	int i = 0;
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	if (i >= (int)literal.length()) return false;
	bool isDot = false;
	while (literal[i])
	{
		if (literal[i] == '.'){
			if (isDot)	return (false);
			isDot = true;
		}
		else if (!isdigit(literal[i])) return (false);
		i++;
	}
	if (isDot == false) return (false);
	try{
		std::stod(literal);
	} catch (std::invalid_argument const& e){
		std::cout << "double std::invalid_argument::what(): " << e.what() << '\n';
		return (false);
	} catch (std::out_of_range const& e){
		std::cout << "double std::out_of_range::what(): " << e.what() << '\n';
		return (false);
	}
	return (true);
}
bool	TypeDetector::isSpecialFloat(const std::string &literal)
{
	for (int i = 0; i < 3; i++)
	{
		if (literal == specialFloat[i])
			return (true);
	}
	return (false);
}
bool	TypeDetector::isSpecialDouble(const std::string &literal)
{
	for (int i = 0; i < 3; i++)
	{
		if (literal == specialDouble[i])
			return (true);
	}
	return (false);
}
type	TypeDetector::getType(const std::string &literal)
{
	if (isSpecialFloat(literal)) return (T_FLOAT);
	if (isSpecialDouble(literal)) return (T_DOUBLE);
	if (isChar(literal)) return (T_CHAR);
	if (isInt(literal)) return (T_INT);
	if (isFloat(literal)) return (T_FLOAT);
	if (isDouble(literal)) return (T_DOUBLE);
	return (T_INVALID);
}
