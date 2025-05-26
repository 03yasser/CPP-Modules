#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <iterator>
#include <string>
#include <iomanip>

class BitcoinExchange
{
	private :
		std::map<std::string, float>	data;
		std::string date;
		std::string value;
		float val;

		void loadData(const std::string &Database);
		int parseData(const std::string &line);
		int parseInput(const std::string &line);
		int validateDate(const std::string &date);
		int validateValue();
	public :
		// Canonical form
		BitcoinExchange(void);
		BitcoinExchange(std::string const &filename, const std::string &Database);
		BitcoinExchange(BitcoinExchange const &copy);
		~BitcoinExchange(void);
		BitcoinExchange& operator=(const BitcoinExchange &other);
};

#endif