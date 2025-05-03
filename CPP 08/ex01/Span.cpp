#include "Span.hpp"


Span::Span(void) {}

Span::Span(const Span &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->N = copy.N;
	this->V = copy.V;
	*this = copy;
}

Span::~Span(void)
{
	// std::cout << "Span is destroyed" << std::endl;
}

Span& Span::operator=(const Span &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->N = other.N;
		this->V = other.V;
	}
	return (*this);
}

Span::Span(unsigned int N) : N(N) {}

// Member functions

void Span::addNumber(int n)
{
	if (V.size() >= N)
		throw std::out_of_range("Span is full");
	V.push_back(n);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (std::distance(begin, end) > static_cast<int>(N - V.size()))
        throw std::out_of_range("Not enough space in Span");
    V.insert(V.end(), begin, end);
}

int Span::shortestSpan(void)
{
	int tmp;

	if (V.size() < 2)
		throw std::out_of_range("Not enough numbers");
	std::vector<int> copy = V;
	std::sort(copy.begin(), copy.end());
	int min = INT_MAX;
	for (size_t i = 0; i < copy.size() - 1; i++)
	{
		tmp = copy[i + 1] - copy[i];
		if (tmp < min)
			min = tmp;
	}
	return min;
}

int Span::longestSpan(void)
{
	if (V.size() < 2)
		throw std::out_of_range("Not enough numbers");
	std::vector<int> copy = V;
	std::sort(copy.begin(), copy.end());
	return (copy.back() - copy.front());
}