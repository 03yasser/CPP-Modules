#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(std::string const &filename, const std::string &Database)
{
	loadData(Database);

	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file");
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
	{
		std::cerr << "Error: date | value" << line << std::endl;
		file.close();
		return;
	}
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
		std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << (it->second * val) << std::endl;
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
		val = std::strtod(value.c_str(), NULL);
		data[date] = val;
	}
	file.close();
}

int BitcoinExchange::parseInput(const std::string &line)
{
	if (line.empty())
		return 1;

	int decimalpoint = 0;
	size_t pos = line.find('|');
	if (pos == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return 1;
	}
	if (pos == 0 || pos == line.size() - 1 || line[pos - 1] != ' ' || line[pos + 1] != ' ')
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return 1;
	}

	date = line.substr(0, pos - 1);
	value = line.substr(pos + 2);
	// std::cout << "date: |" << date << "|" << ", value: |" << value <<"|" << std::endl;
	// check if value empty also for spaces
	int tmp = 0;
	for (size_t i = 0; i < value.size(); i++)
	{
		if (value[i] == ' ')
			tmp++;
	}
	if (date.empty() || value.empty() || (tmp == static_cast<int>(value.size())))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return 1;
	}
	if (validateDate(date))
		return 1;
	size_t i = 0;
	while(value[i] == ' ' && i < value.size())
		i++;
	if(value[0] == '-' || value[0] == '+')
		i++;
	for ( ; i < value.size(); i++)
	{
		if (value[i] == '.' && i == value.size() - 1)
		{
			std::cerr << "Error: bad input => " << value << std::endl;
			return 1;
		}
		if (value[i] == '.')
		{
			++decimalpoint;
			continue;
		}
		if (!isdigit(value[i]))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			return 1;
		}
	}
	if (decimalpoint > 1)
	{
		std::cerr << "Error: bad input => " << value << std::endl;
		return 1;
	}
	val = std::strtod(value.c_str(), NULL);
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
	int year = 0, month = 0, day = 0;
	for (int i = 0; i < 4; i++)
		year = year * 10 + (date[i] - '0');
	month = (date[5] - '0') * 10 + (date[6] - '0');
	day = (date[8] - '0') * 10 + (date[9] - '0');
	if (month < 1 || month > 12 || day < 1 || day > 31 || year > 2025)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return 1;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return 1;
	}
	if (month == 2)
	{
		if (day > 29 || (day == 29 && year % 4 != 0))
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