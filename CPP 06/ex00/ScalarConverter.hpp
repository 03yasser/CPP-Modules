#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <stdlib.h>
# include <climits>
# include <limits>
# include <cfloat>

enum varType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INFF,
	INFD,
	NAN,
	error
};

class ScalarConverter
{
	private :
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &copy);
		ScalarConverter& operator=(const ScalarConverter &other);
		static varType getType(std::string const &input);
		
	public :
		~ScalarConverter(void);

		// Methods
		static void convert(std::string const &input);
};

#endif