#include "ScalarConverter.hpp"
#include "TypeDetector.hpp"


ScalarConverter::ScalarConverter()
{}

// ScalarConverter::ScalarConverter(const ScalarConverter &src)
// {}
// ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
// {}

ScalarConverter::~ScalarConverter()
{}

void	ScalarConverter::convert(const std::string &literal)
{
	type typeOfString = TypeDetector::getType(literal);

	char cVal;
	int iVal;
	float fVal;
	double dVal;

	try{
		switch(typeOfString)
		{
			case T_CHAR:
				cVal = literal[0];
				iVal = static_cast<int>(cVal);
				fVal = static_cast<float>(cVal);
				dVal = static_cast<double>(cVal);
			case T_INT:
				iVal = std::stoi(literal);
				cVal = static_cast<char>(iVal);
				fVal = static_cast<float>(iVal);
				dVal = static_cast<double>(iVal);
			case T_FLOAT:
				fVal = std::stof(literal);
				cVal = static_cast<char>(fVal);
				iVal = static_cast<int>(fVal);
				dVal = static_cast<double>(fVal);
			case T_DOUBLE:
				dVal = std::stod(literal);
				cVal = static_cast<char>(dVal);
				iVal = static_cast<int>(dVal);
				fVal = static_cast<float>(dVal);
			default:
				break;
		}
	}
	catch(...){
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return;
	}

	// Print:
	std::cout << "char: ";
	if (typeOfString == T_INVALID || !TypeDetector::isDisplayable(cVal))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << cVal << "'\n";
	std::cout << "int: ";
	if (typeOfString == T_INVALID)
		std::cout << "impossible\n";
	else
		std::cout << iVal << '\n';
	std::cout << "float: ";
	if (typeOfString == T_INVALID)
		std::cout << "impossible\n";
	else
		std::cout << fVal << 'f' << '\n';
	std::cout << "double: ";
	if (typeOfString == T_INVALID)
		std::cout << "impossible\n";
	else
		std::cout << dVal << '\n';
}