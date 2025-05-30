#include "PmergeMe.hpp"

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

bool PmergeMe::is_sorted(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator it = begin; it != end - 1; ++it)
	{
		if (*it > *(it + 1))
			return false;
	}
	return true;
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
		if (av[i][0] == '\0')
		{
			throw std::invalid_argument("Error: Empty argument provided.");
		}
		for (int j = 0; av[i][j] != '\0'; ++j)
		{
			if (!isdigit(av[i][j]))
			{
				throw std::invalid_argument("Error: Invalid character in input.");
			}
		}
		std::stringstream ss(av[i]);
		unsigned int num;
		ss >> num;
		if (num > 2147483647)
		{
			throw std::invalid_argument("Error: Number out of range.");
		}
		vec.push_back(num);
		deq.push_back(num);

	}
	if (is_sorted(vec.begin(), vec.end()))
	{
		throw std::invalid_argument("Error: Input is already sorted.");
	}
}


void PmergeMe::run(void)
{
	double duration;
    clock_t vec_start, vec_end, deq_start, deq_end;
	
	printBefore();

	vec_start = clock();
	sortVector();
	vec_end = clock();
	deq_start = clock();
	sortDeque();
	deq_end = clock();
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

    std::cout << "Time to process a range of " << deq.size();
    std::cout << " elements with std::deque<>  : ";
    duration = static_cast<double>(deq_end - deq_start) / CLOCKS_PER_SEC;
    std::cout << std::fixed << std::setprecision(5) << duration << " us";
    std::cout << std::endl;

}


template <typename T>
static void jacobsthal(T &c, size_t n)
{
	T v;
	
	v.push_back(0);
	v.push_back(1);
	for (size_t i = 2; i < n + 2; i++)
	{
		v.push_back(v[i - 1] + 2 * v[i - 2]);
	}
	for (size_t i = 2; i < n + 2; i++)
	{
		c.push_back(v[i]);
	}
}

static void sort_vector_pairs(std::vector<std::pair<int, int> > &vecPairs)
{
	for (size_t i = 1; i < vecPairs.size(); ++i)
	{
		while (i > 0 && vecPairs[i].first < vecPairs[i - 1].first)
		{
			std::swap(vecPairs[i], vecPairs[i - 1]);
			--i;
		}
	}
}

void PmergeMe::sortVector(void)
{
	std::vector<std::pair<int, int> > vecPairs;
	std::vector<int> jacobsthalVec;
	int isodd = 0;
	size_t size = vec.size();
	int unpaired;
	if (size % 2 != 0)
	{
		isodd = 1;
		unpaired = vec[size - 1];
		size--;
		vec.pop_back();
	}
	for (size_t i = 0; i < size - 1; i += 2)
	{
		vecPairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		if (vecPairs.back().first < vecPairs.back().second)
		{
			std::swap(vecPairs.back().first, vecPairs.back().second);
		}
	}
	sort_vector_pairs(vecPairs);
	std::vector<int> mainVec, pendVec;
	mainVec.push_back(vecPairs[0].second);
	for (size_t i = 0 ; i < vecPairs.size(); ++i)
	{
		mainVec.push_back(vecPairs[i].first);
		if (i < vecPairs.size() - 1)
		{
			pendVec.push_back(vecPairs[i + 1].second);
		}
	}
	mainVec.reserve(size + 1);
	jacobsthal(jacobsthalVec, pendVec.size());
	size_t Jacob_index = 0;
	for (size_t Pend_index = 0; Pend_index < pendVec.size(); Pend_index++)
	{
		size_t index = jacobsthalVec[Jacob_index];
		
		if (index <= pendVec.size())
		{
			int value = pendVec[index - 1];
			
			std::vector<int>::iterator pos = std::upper_bound(mainVec.begin(),mainVec.end(),value);
			mainVec.insert(pos, value);
			pendVec[index -1] = -1;
			Jacob_index++;
		}
		else
			break;
	}
	for (size_t i = 0; i < pendVec.size(); ++i)
	{
		if (pendVec[i] != -1)
		{
			std::vector<int>::iterator pos = std::upper_bound(mainVec.begin(), mainVec.end(), pendVec[i]);
			mainVec.insert(pos, pendVec[i]);
		}
	}
	if (isodd)
	{
		std::vector<int>::iterator pos;
		pos = std::upper_bound(mainVec.begin(), mainVec.end(),unpaired);
		mainVec.insert(pos, unpaired);
	}
	vec = mainVec;
}

static void sort_deq_pairs(std::deque<std::pair<int, int> > &deqPairs)
{
	for (size_t i = 1; i < deqPairs.size(); ++i)
	{
		while (i > 0 && deqPairs[i].first < deqPairs[i - 1].first)
		{
			std::swap(deqPairs[i], deqPairs[i - 1]);
			--i;
		}
	}
}

void PmergeMe::sortDeque(void)
{
	std::deque<std::pair<int, int> > deqPairs;
	std::deque<int> jacobsthalDeq;
	int isodd = 0;
	size_t size = deq.size();
	int unpaired;
	if (size % 2 != 0)
	{
		isodd = 1;
		unpaired = deq[size - 1];
		size--;
		deq.pop_back();
	}
	for (size_t i = 0; i < size - 1; i += 2)
	{
		deqPairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		if (deqPairs.back().first < deqPairs.back().second)
		{
			std::swap(deqPairs.back().first, deqPairs.back().second);
		}
	}
	sort_deq_pairs(deqPairs);
	std::deque<int> mainDeq, pendDeq;
	mainDeq.push_back(deqPairs[0].second);
	for (size_t i = 0 ; i < deqPairs.size(); ++i)
	{
		mainDeq.push_back(deqPairs[i].first);
		if (i < deqPairs.size() - 1)
		{
			pendDeq.push_back(deqPairs[i + 1].second);
		}
	}
	jacobsthal(jacobsthalDeq, pendDeq.size());
	size_t Jacob_index = 0;
	for (size_t Pend_index = 0; Pend_index < pendDeq.size(); Pend_index++)
	{
		size_t index = jacobsthalDeq[Jacob_index];
		
		if (index <= pendDeq.size())
		{
			int value = pendDeq[index - 1];
			
			std::deque<int>::iterator pos = std::upper_bound(mainDeq.begin(),mainDeq.end(),value);
			mainDeq.insert(pos, value);
			pendDeq[index -1] = -1;
			Jacob_index++;
		}
		else
			break;
	}
	for (size_t i = 0; i < pendDeq.size(); ++i)
	{
		if (pendDeq[i] != -1)
		{
			std::deque<int>::iterator pos = std::upper_bound(mainDeq.begin(), mainDeq.end(), pendDeq[i]);
			mainDeq.insert(pos, pendDeq[i]);
		}
	}
	if (isodd)
	{
		std::deque<int>::iterator pos;
		pos = std::upper_bound(mainDeq.begin(), mainDeq.end(), unpaired);
		mainDeq.insert(pos, unpaired);
	}
	deq = mainDeq;
}