#ifndef RPN_HPP
# define RPN_HPP
#include <iostream>
#include <string>
#include <stack>
#include <exception>
class RPN
{
	private:
		std::string input;
		std::stack<int> numbers;
		bool isOperand(char c);
	public :
		RPN(void);
		RPN(RPN const &copy);
		RPN(std::string input);
		~RPN(void);
		RPN& operator=(const RPN &other);

		void calculate();
};

#endif