#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

		
		MutantStack(void) : std::stack<T>() {}
		MutantStack(MutantStack const &copy)
		{
			*this = copy;
		}
		~MutantStack(void) {}
		MutantStack& operator=(const MutantStack &other)
		{
			if (this != &other)
			{
				this->c = other.c;
			}
			return (*this);
		}

		iterator begin(void)
		{
			return (this->c.begin());
		}
		iterator end(void)
		{
			return (this->c.end());
		}
		reverse_iterator rbegin(void)
		{
			return (this->c.rbegin());
		}
		reverse_iterator rend(void)
		{
			return (this->c.rend());
		}
		
};

#endif