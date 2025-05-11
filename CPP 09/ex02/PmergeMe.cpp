#include "PmergeMe.hpp"
#include <sstream> // For std::stringstream

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe::~PmergeMe(void) {}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->vec = other.vec;
		this->deq = other.deq;
	}
	return (*this);
}

void PmergeMe::printBefore(void)
{
	std::cout << "Before: ";
	for (int i = 0; i < static_cast<int>(vec.size()); ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::checkInput(int ac, char **av)
{
	if (ac < 2)
	{
		throw std::invalid_argument("Error: No arguments provided.");
	}
	for (int i = 1; i < ac; ++i)
	{
		if (av[i][0] == '-')
		{
			throw std::invalid_argument("Error: Negative numbers are not allowed.");
		}
		for (int j = 0; av[i][j] != '\0'; ++j)
		{
			if (!isdigit(av[i][j]))
			{
				throw std::invalid_argument("Error: Invalid character in input.");
			}
		}
		std::stringstream ss(av[i]);
		int num;
		ss >> num;
		vec.push_back(num);
		deq.push_back(num);
	}
}


void PmergeMe::run(void)
{
    clock_t vec_start, vec_end, deq_start, deq_end;
    double duration;

    vec_start = clock();
    mergeinsortvector(vec, 0, vec.size() - 1);
    vec_end = clock();
    
    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size();
    std::cout << " elements with std::vector<> : ";
    duration = static_cast<double>(vec_end - vec_start) / CLOCKS_PER_SEC;
    std::cout << std::fixed << std::setprecision(5) << duration << " us";
    std::cout << std::endl;
    
    deq_start = clock();
    mergeinsortdeque(deq, 0, deq.size() - 1);
    deq_end = clock();

    std::cout << "Time to process a range of " << deq.size();
    std::cout << " elements with std::deque<>  : ";
    duration = static_cast<double>(deq_end - deq_start) / CLOCKS_PER_SEC;
    std::cout << std::fixed << std::setprecision(5) << duration << " us";
    std::cout << std::endl;
}
