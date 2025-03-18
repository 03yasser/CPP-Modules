#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>



struct Data
{
	std::string first_name;
	std::string last_name;
	int age;
	char sex;
};

class Serializer
{
	private :
		Serializer(void);
		Serializer(Serializer const &copy);
		Serializer& operator=(const Serializer &other);
		
	public :
		~Serializer(void);
	
		// Methods
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif