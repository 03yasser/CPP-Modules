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
#include <sstream>

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

void Account::displayAccountsInfos()
{
	std::stringstream	ss;
    _displayTimestamp();
    ss << "accounts:" << _nbAccounts << ";";
    ss << "total:" << _totalAmount << ";";
    ss << "deposits:" << _totalNbDeposits << ";";
    ss << "withdrawals:" << _totalNbWithdrawals;
    std::cout << ss.str() << std::endl;
}

Account::Account() 
{
    std::stringstream ss;

    _displayTimestamp();
    _accountIndex = _nbAccounts;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;

    ss << "index:" << _accountIndex << ";";
    ss << "amount:" << _amount << ";";
    ss << "created" << std::endl;
    std::cout << ss.str();
}

Account::Account(int initial_deposit) 
{
    std::stringstream ss;

    _displayTimestamp();
    _accountIndex = _nbAccounts;
    _totalAmount += initial_deposit;
    _amount = initial_deposit;
    _nbAccounts++;

    ss << "index:" << _accountIndex << ";";
    ss << "amount:" << _amount << ";";
    ss << "created" << std::endl;
    std::cout << ss.str();
}

Account::~Account() 
{
    std::stringstream ss;

    _displayTimestamp();
    ss << "index:" << _accountIndex << ";";
    ss << "amount:" << _amount << ";";
    ss << "closed" << std::endl;
    std::cout << ss.str();
    _nbAccounts--;
}

void Account::makeDeposit(int deposit) 
{
    std::stringstream ss;

    _displayTimestamp();
    _totalAmount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;
    ss << "index:" << _accountIndex << ";";
    ss << "p_amount:" << _amount << ";";
    _amount += deposit;
    ss << "deposit:" << deposit << ";";
    ss << "amount:" << _amount << ";";
    ss << "nb_deposits:" << _nbDeposits << std::endl;
    std::cout << ss.str();
}

bool Account::makeWithdrawal(int withdrawal) 
{
    _displayTimestamp();

    std::stringstream ss;

    ss << "index:" << _accountIndex << ";";
    ss << "p_amount:" << _amount << ";";
    if (_amount - withdrawal >= 0) 
	{
        ss << "withdrawal:" << withdrawal << ";";
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        ss << "amount:" << _amount << ";";
        ss << "nb_withdrawals:" << _nbWithdrawals << std::endl;
        
        _totalNbWithdrawals++;
        _nbWithdrawals++;
        std::cout << ss.str();
        return true;
    } 
	else 
	{
        ss << "withdrawal:refused" << std::endl;
        std::cout << ss.str();
        return false;
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