#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ScalarConverter::~ScalarConverter(void)
{
	// std::cout << "ScalarConverter is destroyed" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	(void)other;
	return (*this);
}

// Methods

varType ScalarConverter::getType(std::string const &input)
{
	if (input.length() == 1 && std::isalpha(input[0]))
		return CHAR;
	if (input == "-inff" || input == "+inff")
		return INFF;
	if (input == "inf" || input == "+inf")
		return INFD;
	if (input == "nan" || input == "nanf")
		return NAN;

	char *end;
	std::strtol(input.c_str(), &end, 10);
	if (*end == '\0')
		return INT;
	std::strtof(input.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0' && *(end - 1) != '.')
		return FLOAT;
	std::strtod(input.c_str(), &end);
	if (*end == '\0' && *(end - 1) != '.')
		return DOUBLE;
	return error;
}

void convertChar(std::string const &input)
{
	char c = input[0];
	if (std::isprint(c))
		std::cout << "Char: '" << c << "'" << std::endl;
	else
		std::cout << "Char: Non displayable" << std::endl;
	std::cout << "Int: " << static_cast<int>(c) << std::endl;
	std::cout << "Float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "Double: " << static_cast<double>(c) << ".0" << std::endl;
}

void convertInt(std::string const &input)
{
	long int i = std::strtol(input.c_str(), NULL, 10);
	if (i >= 32 && i <= 126)
		std::cout << "Char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "Char: Non displayable" << std::endl;
	if (i >= INT_MIN && i <= INT_MAX)
	{
		std::cout << "Int: " << i << std::endl;
		std::cout << "Float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << "Double: " << static_cast<double>(i) << ".0" << std::endl;
	}
	else
	{
		std::cout << "Int: Impossible" << std::endl;
		std::cout << "Float: Impossible" << std::endl;
		std::cout << "Double: Impossible" << std::endl;
	}
}

void	convertFloat(std::string const &input)
{
	float f = std::strtof(input.c_str(), NULL);
	if (f >= 32 && f <= 126)
		std::cout << "Char: '" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "Char: Non displayable" << std::endl;
	std::cout << "Int: " << static_cast<int>(f) << std::endl;
	if (f >= FLT_MIN && f <= FLT_MAX)
		std::cout << "Float: " << f << "f" << std::endl;
	else
		std::cout << "Float: Impossible" << std::endl;
	std::cout << "Double: " << static_cast<double>(f) << std::endl;
}

void convertDouble(std::string const &input)
{
	double d = std::strtod(input.c_str(), NULL);
	if (d >= 32 && d <= 126)
		std::cout << "Char: '" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "Char: Non displayable" << std::endl;
	std::cout << "Int: " << static_cast<int>(d) << std::endl;
	std::cout << "Float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "Double: " << d << std::endl;
}

void ScalarConverter::convert(std::string const &input)
{
	if (input.empty())
	{
		std::cout << "Error: Empty input" << std::endl;
		return ;
	}
	varType type = getType(input);
	switch (type)
	{
		case CHAR:
			convertChar(input);
			break;
		case INT:
			convertInt(input);
			break;
		case FLOAT:
			convertFloat(input);
			break;
		case DOUBLE:
			convertDouble(input);
			break;
		case INFF:
		{
			std::cout << "Char: Impossible" << std::endl;
			std::cout << "Int: Impossible" << std::endl;
			std::cout << "Float: " << input << std::endl;
			std::string tmp  = input;
			tmp.at(4) = '\0';
			std::cout << "Double: " << tmp << std::endl;
			break;
		}
		case INFD:
			std::cout << "Char: Impossible" << std::endl;
			std::cout << "Int: Impossible" << std::endl;
			std::cout << "Float: " << input << 'f' << std::endl;
			std::cout << "Double: " << input << std::endl;
			break;
		case NAN:
		{
			std::cout << "Char: Impossible" << std::endl;
			std::cout << "Int: Impossible" << std::endl;
			std::cout << "Float: nanf" << std::endl;
			std::cout << "Double: nan" << std::endl;
			break;
		}
		default:
			std::cout << "Error: Invalid input" << std::endl;
			break;
	}
}

