
#ifndef SAVINGS_H

#define SAVINGS_H

// Constructor
class savings {

	// Members are accessible from outside the class
	public:

		void calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears);
		void balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears);

	// Members cannot be accessed (or viewed) from outside the class
	private:
		double initialInvestment;
		double monthlyDeposit;
		double interestRate;
		int numberOfYears;

};
#endif
