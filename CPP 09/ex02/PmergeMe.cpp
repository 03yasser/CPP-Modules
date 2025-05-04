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


void PmergeMe::insertionSortVector(std::vector<int>& vec, int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
	{
        int key = vec[i];
        int j = i;
        while (j > left && vec[j - 1] > key) {
            vec[j] = vec[j - 1];
            --j;
        }
        vec[j] = key;
    }
}

void PmergeMe::insertionSortDeque(std::deque<int>& deq, int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
	{
        int key = deq[i];
        int j = i;
        while (j > left && deq[j - 1] > key)
		{
            deq[j] = deq[j - 1];
            --j;
        }
        deq[j] = key;
    }
}

void PmergeMe::mergeinsortvector(std::vector<int> &vec, int left, int right)
{
	if (right - left <= 10)
	{
		insertionSortVector(vec, left, right);
		return;
	}
	int mid = left + (right - left) / 2;
	mergeinsortvector(vec, left, mid);
	mergeinsortvector(vec, mid + 1, right);

	std::vector<int> temp(right - left + 1);
	int i = left, j = mid + 1, k = 0;

	while (i <= mid && j <= right)
	{
		if (vec[i] <= vec[j])
			temp[k++] = vec[i++];
		else
			temp[k++] = vec[j++];
	}

	while (i <= mid)
		temp[k++] = vec[i++];
	while (j <= right)
		temp[k++] = vec[j++];

	for (int i = left; i <= right; ++i)
		vec[i] = temp[i - left];
}

void PmergeMe::mergeinsortdeque(std::deque<int> &deq, int left, int right)
{
	if (right - left <= 10)
	{
		insertionSortDeque(deq, left, right);
		return;
	}
	int mid = left + (right - left) / 2;
	mergeinsortdeque(deq, left, mid);
	mergeinsortdeque(deq, mid + 1, right);

	std::deque<int> temp(right - left + 1);
	int i = left, j = mid + 1, k = 0;

	while (i <= mid && j <= right)
	{
		if (deq[i] <= deq[j])
			temp[k++] = deq[i++];
		else
			temp[k++] = deq[j++];
	}

	while (i <= mid)
		temp[k++] = deq[i++];
	while (j <= right)
		temp[k++] = deq[j++];

	for (int i = left; i <= right; ++i)
		deq[i] = temp[i - left];

}