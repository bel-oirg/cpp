#include "Account.hpp"
#include <ostream>
#include <iomanip>
#include <iostream>
#include <sstream> //added for ostringstram
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void    Account::_displayTimestamp(void)
{
    time_t				now;
    tm					*raw;
    std::ostringstream	oss;
    /*
        std::ostringstream provides a way to create
		a string stream that can be used to perform input
        and output operations on strings
    */
    now = time(0); //time now on current OS
    raw = localtime(&now);
	/*
		setw -> to set the width by deafault filled with ' '
		setfill -> to fill
	*/
    oss << "["
        << raw->tm_year + 1900
        << std::setw(2) << std::setfill('0') << raw->tm_mon + 1
        << std::setw(2) << std::setfill('0') << raw->tm_mday
        << "_" 
        << std::setw(2) << std::setfill('0') << raw->tm_hour 
        << std::setw(2) << std::setfill('0') << raw->tm_min 
        << std::setw(2) << std::setfill('0') << raw->tm_sec
        << "]";
	/*
		str() Returns the current contents of the string stream.
	*/
    std::cout << oss.str();
}

Account::Account(int dep)
{
    _amount = dep;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _accountIndex = _nbAccounts++;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:"<< _amount
              << ";created" << std::endl;
}

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void    Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals()
              << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";p_amount:"<< _amount
              << ";deposit:" << deposit
              << ";amount:" << _amount + deposit
              << ";nb_deposits:" << ++_nbDeposits
              << std::endl;
    _totalNbDeposits++;
    _amount += deposit;
    _totalAmount += deposit;
}

bool    Account::makeWithdrawal(int withd)
{
    _displayTimestamp();
    if (_amount < withd)
    {
        std::cout << " index:" << _accountIndex
                  << ";p_amount:"<< _amount
                  << ";withdrawal:refused"
                  << std::endl;
        return (false);
    }
    std::cout << " index:" << _accountIndex
            << ";p_amount:"<< _amount
            << ";withdrawal:" << withd
            << ";amount:" << _amount - withd
            << ";nb_withdrawals:" << ++_nbWithdrawals
            << std::endl;
    _amount -= withd;
    _totalNbWithdrawals++;
    _totalAmount -= withd;
    return (true);
}

/*
    the const method means that the function does not modify
    any member variables of the class
*/

int Account::checkAmount(void) const 
{
    return (_totalAmount);
}

void    Account::displayStatus(void) const
{
    _displayTimestamp();

    std::cout << " index:" << _accountIndex
              << ";amount:"<< _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();

    std::cout << " index:" << _accountIndex
              << ";amount:"<< _amount
              << ";closed" << std::endl;
}
/*
    -> std::vector is a sequence container
    that encapsulates dynamic size arrays.
*/

/*
    the desctuctor is called in the reverse order 
    this is because C++ uses a stack for managing object lifetimes.
    to ensure that if an object depends on another it will be destroyed
    in the right order
*/

/*
    foreach() is a standard algorithm in the C++ Standard Library
    that applies a given function to each element
    in a specified range.

    std::mem_fun_ref is a function adapter that turns
    a member function pointer into a function object.
*/