#include "RPN.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: Wrong number of arguments" << std::endl;
        return (1);
    }
    RPN rpn(argv[1]);
    try
    {
        rpn.calculate();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}