#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(std::string input) : input(input)
{
	if (input.empty())
		throw std::runtime_error("Empty input");
}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN::~RPN(void) {}

RPN& RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->input = other.input;
		this->numbers = other.numbers;
	}
	return (*this);
}
bool RPN::isOperand(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}
void RPN::calculate()
{
	int a;
	int b;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == ' ')
			continue;
		if (isdigit(input[i]))
			numbers.push(input[i] - '0');
		else if (isOperand(input[i]))
		{
			if (numbers.size() < 2)
				throw std::runtime_error("Not enough operands");
			b = numbers.top();
			numbers.pop();
			a = numbers.top();
			numbers.pop();
			switch (input[i])
			{
				case '+':
					numbers.push(a + b);
					break;
				case '-':
					numbers.push(a - b);
					break;
				case '*':
					numbers.push(a * b);
					break;
				case '/':
					if (b == 0)
						throw std::runtime_error("Division by zero");
					numbers.push(a / b);
					break;
			}
		}
		else
			throw std::runtime_error("Invalid character");
	}
	if (numbers.size() != 1)
		throw std::runtime_error("Invalid expression");
	std::cout << numbers.top() << std::endl;
}