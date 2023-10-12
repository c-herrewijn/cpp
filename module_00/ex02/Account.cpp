#include "Account.hpp"

Account::Account( int initial_deposit ) {}
Account::~Account( void ) {}

int Account::getNbAccounts(void) {
    return (0);  // dummy
}
int Account::getTotalAmount(void) {
    return (0);  // dummy
}
int Account::getNbDeposits(void) {
    return (0);  // dummy
}
int Account::getNbWithdrawals(void) {
    return (0);  // dummy
}
void Account::displayAccountsInfos(void) {}

void Account::makeDeposit( int deposit ) {}
bool Account::makeWithdrawal( int withdrawal ) {
    return (true);  // dummy
}
int Account::checkAmount( void ) const {
    return (0);  // dummy
}
void Account::displayStatus( void ) const {}

static void	_displayTimestamp( void ) {}