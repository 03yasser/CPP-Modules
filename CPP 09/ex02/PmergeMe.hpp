#ifndef PMERGEME_HPP
# define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <ctime>
#include <deque>
#include <exception>
#include <iomanip>
#include <sstream>
#include <algorithm> 

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::deque<int> deq;
		
		public :
		PmergeMe(void);
		PmergeMe(PmergeMe const &copy);
		~PmergeMe(void);
		PmergeMe& operator=(const PmergeMe &other);
		void checkInput(int ac, char **av);
		void printBefore(void);
		void run(void);
		void sortVector(void);
		void sortDeque(void);
		bool is_sorted(std::vector<int>::iterator begin, std::vector<int>::iterator end);

};

#endif