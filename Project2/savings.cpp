// Headers included
#include "savings.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Outputs the calculated results of each years investment details in 3 separate fields
// Format text aligned right, sets space inbetween fields, and fixed decimal to 2
void printDetails(int year, double yearEndBalance, double interestEarned) {
	cout << right << setw(5) << year << fixed << setprecision(2)

		<< setw(20) << "$" << yearEndBalance

		<< setw(29) << "$" << interestEarned << endl << endl;
}

// Calculates and returns an end of year balance for given number of years without monthly deposit
void savings::calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {

	// Outputs table of balance and interested without monthly deposit
	cout << " Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "==========================================================================" << endl;
	cout << setw(5) << "Year";
	cout << setw(24) << "Year End Balance";
	cout << setw(37) << "Year End Earned Interest" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	
	// Declare variables
	// Initialize to start year at 1 and interestEarned as 0
	// Initialize yearendbalance start at initial investment
	int year = 1;
	double yearEndBalance = initialInvestment;
	double interestEarned = 0.0;

	// Continues the loop until it equates to number of years user inputted
	while (year <= numberOfYears) {

		// Calculates interest
		double interestEarned = (yearEndBalance) * (interestRate / 100);

		// Adds the interest to the  yearly balance
		yearEndBalance += interestEarned;

		// Outputs the year, yearly balance, and interested earned per year
		printDetails(year,yearEndBalance,interestEarned);

		// Increase the year by one
		year++;

	// End of while loop
	}

// End of function to calcluate without monthly balance
}

// Calculates and returns an end of year balance for given number of years with monthly deposit
void savings::balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) {
	
	// Outputs table of balance and interested with monthly deposit
	cout << " Balance and Interest with Additional Monthly Deposits" << endl;
	cout << "==========================================================================" << endl;
	cout << setw(5) << "Year";
	cout << setw(24) << "Year End Balance";
	cout << setw(37) << "Year End Earned Interest" << endl;
	cout << "--------------------------------------------------------------------------" << endl;

	// Declare variables
	int year = 1;
	double yearEndBalance = initialInvestment;
	double interestEarned = 0.0;
	double interestEarnedMonthly = 0.0;

	// When the year is less than numberOfYearsm while loop will execute
	while (year <= numberOfYears) 
	{

		// Declare variables
		int month = 1;
		double monthEndBalance = yearEndBalance;

		// When the month is less than 12 while loop will execute
		while (month <= 12)
		{

			// Calculates interest
			interestEarnedMonthly = (yearEndBalance + monthlyDeposit) * ((interestRate / 100) / 12);

			// Adds the interest to the  yearly balance
			yearEndBalance += monthlyDeposit + interestEarnedMonthly;

			interestEarned += interestEarnedMonthly;

			// Increase the month by one
			month++;

		// End of inner while loop
		}

		// Outputs the year, yearly balance, and interested earned per year
		printDetails(year, yearEndBalance, interestEarned);

		// Resets interestEarned back to 0 to see interest per year 
		// instead of accumulated amount
		interestEarned = 0.0;

		// Increase the year by one
		year++;

	// End of outer while loop
	}

// End of function to calcluate with monthly balance
}
