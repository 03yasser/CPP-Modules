#ifndef PMERGEME_HPP
# define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <deque>
#include <exception>
#include <iomanip>


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
		void insertionSortVector(std::vector<int> &vec, int left, int right);
		void insertionSortDeque(std::deque<int> &deq, int left, int right);		
		void mergeinsortvector(std::vector<int> &vec, int left, int right);
		void mergeinsortdeque(std::deque<int> &deq, int left, int right);
};

#endif