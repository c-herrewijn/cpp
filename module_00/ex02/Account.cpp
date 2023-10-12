#include "Account.hpp"
#include <ctime>
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
    return (0); // dummy
}

int Account::getTotalAmount(void)
{
    return (0); // dummy
}

int Account::getNbDeposits(void)
{
    return (0); // dummy
}

int Account::getNbWithdrawals(void)
{
    return (0); // dummy
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
    std::cout << "[" << "1234" << "]";
}