/* Winnie Kwong
*  Professor Foster
*  CS-210 - Programming Languages
*  March 26th, 2023
*  Project Two: Airgead Banking
*/

// Headers used
#include <iostream>
#include "savings.h"
using namespace std;

int main() {

	// Declare Vaiables
	double initialInvestment, monthlyDeposit, interestRate;
	int numberOfYears;

	// Display form to user
	cout << "*********************************" << endl;
	cout << "*********** Data Input **********" << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;

	// Windows-specific command, which tells the OS to run the pause program
	// This program waits to be terminated, and halts the exceution of the parent C++ program
	// Only after the pause program is terminated, will the original program continue
	system("pause");

	cout << endl;

	// Prompts to retrieve initial investment, monthly deposit,
	//	interest rate, and number of years
	cout << "*************************************" << endl;
	cout << "*************Data Input**************" << endl;
	cout << "Initial Investment Amount: $";
	cin >> initialInvestment;
	cout << "Monthly Deposit: $";
	cin >> monthlyDeposit;
	cout << "Annual Interest: %";
	cin >> interestRate;
	cout << "Number of years: ";
	cin >> numberOfYears;

	// Windows-specific command, which tells the OS to run the pause program
	// This program waits to be terminated, and halts the exceution of the parent C++ program
	// Only after the pause program is terminated, will the original program continue
	system("pause");

	// Outputs new line
	cout << endl;

	// Creates an object of class
	savings bankAccount;

	// Call the method
	// Calculates and returns an end of year balance for given number of years
	bankAccount.calculateBalanceWithoutMonthlyDeposit(initialInvestment, interestRate, numberOfYears);

	// Outputs new line
	cout << endl;

	// Loop that calls method to include monthly deposit
	while (monthlyDeposit > 0) 
	{ 
		// Calls method
		// Calculates and returns an end of year balance for a given number of years with monthly deposit
		bankAccount.balanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, interestRate, numberOfYears);
		break;

	// End of while loop
	} 

	// If user wants to try again
	cout << endl << "Reset information and do another? (Press y to continue): ";
	// Decalre variable
	string option;
	// Prompt input
	cin >> option;

	// If user wants to continue, return to main() function
	if (option == "y") 
	{ 
		cout << endl;
		return main();

	// End of if statement
	} 
	
	// Else, breaks out of loop
	else 
	{ 
	cout << endl;

	// End of else statement
	} 

// Exits program
return 0;

// End of main function
}