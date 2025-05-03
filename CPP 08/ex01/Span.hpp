#ifndef SPAN_HPP
# define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <exception>
#include <climits>
class Span
{
	private :
		unsigned int		N;
		std::vector<int>	V;

	public :
		Span(void);
		Span(Span const &copy);
		~Span(void);
		Span& operator=(const Span &other);
		Span(unsigned int N);

		// Member functions
		void addNumber(int n);
		int shortestSpan(void);
		int longestSpan(void);
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

};

#endif