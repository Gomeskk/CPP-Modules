#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// Initialize static members
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Returns the number of accounts
int Account::getNbAccounts(void) {
    return _nbAccounts;
}

// Returns the total amount across all accounts
int Account::getTotalAmount(void) {
    return _totalAmount;
}

// Returns the total number of deposits across all accounts
int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

// Returns the total number of withdrawals across all accounts
int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

// Display timestamp in format [YYYYMMDD_HHMMSS]
void Account::_displayTimestamp(void) {
    std::time_t currentTime = std::time(NULL);
    std::tm* localTime = std::localtime(&currentTime);
    
    std::cout << "[" 
              << std::setfill('0') << std::setw(4) << localTime->tm_year + 1900
              << std::setfill('0') << std::setw(2) << localTime->tm_mon + 1
              << std::setfill('0') << std::setw(2) << localTime->tm_mday
              << "_"
              << std::setfill('0') << std::setw(2) << localTime->tm_hour
              << std::setfill('0') << std::setw(2) << localTime->tm_min
              << std::setfill('0') << std::setw(2) << localTime->tm_sec
              << "] ";
}

// Display account information for all accounts
void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts 
              << ";total:" << _totalAmount 
              << ";deposits:" << _totalNbDeposits 
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Constructor with initial deposit
Account::Account(int initial_deposit) {
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";created" << std::endl;
}

// Destructor
Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";closed" << std::endl;
}

// Make a deposit into the account
void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";deposit:" << deposit;
    
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    
    std::cout << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits << std::endl;
}

// Make a withdrawal from the account
bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount;
    
    if (_amount < withdrawal) {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    
    std::cout << ";withdrawal:" << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

// Check the amount in the account
int Account::checkAmount(void) const {
    return _amount;
}

// Display the status of the account
void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}
