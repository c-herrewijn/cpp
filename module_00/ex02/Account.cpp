#include <Account.hpp>

#include <ctime>
#include <iomanip>
#include <iostream>

Account::Account(int initial_deposit) :
    _accountIndex(Account::getNbAccounts()),
    _amount(initial_deposit),
    _nbDeposits(0),
    _nbWithdrawals(0)
{
    Account::_nbAccounts += 1;
    Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->checkAmount() << ";"
              << "created" << std::endl;
}

Account::Account(void) :
    _accountIndex(Account::getNbAccounts()),
    _amount(0),
    _nbDeposits(0),
    _nbWithdrawals(0)
{
    Account::_nbAccounts += 1;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->checkAmount() << ";"
              << "created" << std::endl;
}

Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->checkAmount() << ";"
              << "closed" << std::endl;
}

int Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";"
              << "total:" << Account::getTotalAmount() << ";"
              << "deposits:" << Account::getNbDeposits() << ";"
              << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
    int p_amount = this->checkAmount();
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << p_amount << ";"
              << "deposit:" << deposit << ";"
              << "amount:" << this->checkAmount() << ";"
              << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    int p_amount = this->checkAmount();
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "p_amount:" << p_amount << ";";
    if (withdrawal <= this->checkAmount()) {
        this->_amount -= withdrawal;
        this->_nbWithdrawals += 1;
        Account::_totalAmount -= withdrawal;
        Account::_totalNbWithdrawals += 1;
        std::cout << "withdrawal:" << withdrawal << ";"
                  << "amount:" << this->checkAmount() << ";"
                  << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
        return (true);
    }
    else {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
}

int Account::checkAmount(void) const
{
    return (this->_amount);
}

void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
              << "amount:" << this->checkAmount() << ";"
              << "deposits:" << this->_nbDeposits << ";"
              << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
    time_t curr_time_raw;
    struct tm *t;

    time(&curr_time_raw);
    t = localtime(&curr_time_raw);
    std::cout << std::setfill('0') << "[" << t->tm_year + 1900
              << std::setw(2) << t->tm_mon + 1
              << std::setw(2) << t->tm_mday << "_"
              << std::setw(2) << t->tm_hour
              << std::setw(2) << t->tm_min
              << std::setw(2) << t->tm_sec << "] ";
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
