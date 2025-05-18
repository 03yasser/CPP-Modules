#include "PmergeMe.hpp"


int main(int ac, char **av)
{
    PmergeMe pm;
    try
    {
        pm.checkInput(ac, av);
        pm.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}