#ifndef PMERGEME_HPP
# define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <deque>
#include <exception>
#include <iomanip>
#include <sstream>



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
};

#endif