#include "BitcoinExchange.hpp"



int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
    try
    {
        BitcoinExchange Bitcoin(argv[1], "data.csv");
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
}