#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

Account::Account(int initial_deposit)
{
    // [19920104_091532] index:0;amount:42;created

    Account::_displayTimestamp();
    (void)initial_deposit; // dummy
}

Account::~Account(void)
{
    // [19920104_091532] index:7;amount:8942;closed
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
    // [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
}

void Account::makeDeposit(int deposit)
{
    (void)deposit; // dummy
}

bool Account::makeWithdrawal(int withdrawal)
{
    (void)withdrawal; // dummy
    return (true); // dummy
}

int Account::checkAmount(void) const
{
    return (0); // dummy
}

void Account::displayStatus(void) const
{
    // [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
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
