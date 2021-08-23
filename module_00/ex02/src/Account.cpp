#include "Account.hpp"
#include <ctime>
#include <iostream>

// static members

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int		Account::getNbAccounts( void ) { return (_nbAccounts); }
int		Account::getTotalAmount( void ) { return (_totalAmount); }
int		Account::getNbDeposits( void ) { return (_totalNbDeposits); }
int		Account::getNbWithdrawals( void ) { return (_totalNbWithdrawals); }

void	Account::displayAccountsInfos( void ) {

	_displayTimestamp();
	std::cout
		<< " accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit ) :
_accountIndex(_nbAccounts),
_amount(initial_deposit),
_nbDeposits(0),
_nbWithdrawals(0) {

	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
}

Account::~Account( void ) {

	_nbAccounts--;
	_totalAmount -= _amount;

	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit ) {

	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";p_amount:" << _amount;

	if (deposit > 0) {

		_amount += deposit;
		_nbDeposits++;

		_totalAmount += deposit;
		_totalNbDeposits++;

		std::cout
			<< ";deposit:" << deposit
			<< ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits << std::endl;
	} else
		std::cout << ";deposit:refused" << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {

	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";p_amount:" << _amount;

	if (_amount - withdrawal >= 0) {

		_amount -= withdrawal;
		_nbWithdrawals++;

		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;

		std::cout
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	} else {
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
}

void	Account::displayStatus( void ) const {

	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}


int		Account::checkAmount( void ) const { return (_amount); }

void	Account::_displayTimestamp( void ) {

	time_t		now = time(NULL);
	struct tm	tstruct;
	char		buf[20];

	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", &tstruct);
	std::cout << buf;
}

Account::Account( void ) :
_accountIndex(_nbAccounts),
_amount(0),
_nbDeposits(0),
_nbWithdrawals(0) {

	_nbAccounts++;
	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
}

