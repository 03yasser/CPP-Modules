#include "Serializer.hpp"


int main()
{
    Data data;
    data.first_name = "John";
    data.last_name = "Doe";
    data.age = 42;
    data.sex = 'M';
    // print the date before serialization
    std::cout << "Before serialization:" << std::endl;
    std::cout << "First name: " << data.first_name << std::endl;
    std::cout << "Last name: " << data.last_name << std::endl;
    std::cout << "Age: " << data.age << std::endl;
    std::cout << "Sex: " << data.sex << std::endl;

    uintptr_t serialized = Serializer::serialize(&data);
    Data* deserialized = Serializer::deserialize(serialized);
    
    std::cout << "After serialization:" << std::endl;
    std::cout << "First name: " << deserialized->first_name << std::endl;
    std::cout << "Last name: " << deserialized->last_name << std::endl;
    std::cout << "Age: " << deserialized->age << std::endl;
    std::cout << "Sex: " << deserialized->sex << std::endl;
}