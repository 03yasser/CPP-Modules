#include "BitcoinExchange.hpp"
#include <string>




BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(std::string const &filename, const std::string &Database)
{
	loadData(Database);

	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file");
	std::string line;
	std::getline(file, line);
	while (!file.eof())
	{
		getline(file, line);
		if (parseInput(line))
			continue;
		std::map<std::string, float>::iterator it = data.find(date);
		if (it == data.end())
		{
			it = data.lower_bound(date);
			if (it == data.begin() && it->first != date)
				continue;
			if (it == data.end() || it->first != date)
				--it;
		}

		std::cout << date << " => " << val << " = " << it->second * val << std::endl;
	}
	file.close();

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->data = other.data;
	return (*this);
}
void BitcoinExchange::loadData(const std::string &database)
{
	float val;
	std::ifstream file(database.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file");
	std::string line;
	std::getline(file, line);
	while (!file.eof())
	{
		getline(file, line);
		if (parseData(line))
			continue;
		val = std::strtof(value.c_str(), NULL);
		data[date] = val;
	}
	file.close();
}

int BitcoinExchange::parseInput(const std::string &line)
{
	if (line.empty())
		return 1;
	size_t pos = line.find('|');
	if (pos == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return 1;
	}
	date = line.substr(0, pos - 1);
	value = line.substr(pos + 2);

	if (date.empty() || value.empty())
		return 1;
	if (validateDate(date))
		return 1;
	val = std::strtof(value.c_str(), NULL);
	if (validateValue())
		return 1;
	return 0;
}

int BitcoinExchange::parseData(const std::string &line)
{
	if (line.empty())
		return 1;
	size_t pos = line.find(',');
	if (pos == std::string::npos)
		return 1;
	date = line.substr(0, pos);
	value = line.substr(pos + 1);
	if (date.empty() || value.empty())
		return 1;
	return 0;
}

int BitcoinExchange::validateDate(const std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return 1;
	}
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			return 1;
		}
	}
	return 0;
}

int BitcoinExchange::validateValue()
{
	if (val < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return 1;
	}
	if (val > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return 1;
	}
	return 0;
}