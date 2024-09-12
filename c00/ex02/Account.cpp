/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:19:33 by yboutsli          #+#    #+#             */
/*   Updated: 2024/09/12 17:25:57 by yboutsli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" + std::to_string(_nbAccounts) + ";";
	std::cout << "total:" + std::to_string(_totalAmount) + ";";
	std::cout << "deposits:" + std::to_string(_totalNbDeposits) + ";";
	std::cout << "withdrawals:" + std::to_string(_totalNbWithdrawals) << std::endl;
}

Account::Account()
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	std::cout << "index:" + std::to_string(_accountIndex) + ";";
	std::cout << "amount:" + std::to_string(_amount) + ";";
	std::cout << "created" << std::endl;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_nbAccounts++;
	std::cout << "index:" + std::to_string(_accountIndex) + ";";
	std::cout << "amount:" + std::to_string(_amount) + ";";
	std::cout << "created" << std::endl;
}
Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" + std::to_string(_accountIndex) + ";";
	std::cout << "amount:" + std::to_string(_amount) + ";";
	std::cout << "closed" << std::endl;
	_nbAccounts--;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	std::cout << "index:" + std::to_string(_accountIndex) + ";";
	std::cout << "p_amount:" + std::to_string(_amount) + ";";
	std::cout << "deposit:" + std::to_string(deposit) + ";";
	_amount += deposit;
	std::cout << "amount:" + std::to_string(_amount) + ";";
	std::cout << "nb_deposits:" + std::to_string(_nbDeposits) << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" + std::to_string(_accountIndex) + ";";
	std::cout << "p_amount:" + std::to_string(_amount) + ";";
	if (_amount - withdrawal >= 0)
	{
		std::cout << "withdrawal:" + std::to_string(withdrawal) + ";";
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << "amount:" + std::to_string(_amount) + ";";
		std::cout << "nb_withdrawals:" + std::to_string(_nbDeposits) << std::endl;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		return (true);
	}
	else
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}

}

int		Account::checkAmount() const
{
	return (_amount);
}
void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp()
{
	std::time_t now = std::time(0);
	std::tm *localTime = std::localtime(&now);
	std::cout << "[" << localTime->tm_year + 1900
	<< std::setw(2) << std::setfill('0') << localTime->tm_mon
	<< std::setw(2) << std::setfill('0') << localTime->tm_mday
	<< "_"
	<< std::setw(2) << std::setfill('0') << localTime->tm_hour
	<< std::setw(2) << std::setfill('0') << localTime->tm_min
	<< std::setw(2) << std::setfill('0') << localTime->tm_sec
	<< "] ";
}