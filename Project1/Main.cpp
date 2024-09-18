/* Winnie Kwong
*  Professor Foster
*  CS-210 - Programming Languages
*  March 14th, 2023
*  Project One: Chada Tech Clock
*/

// Headers used
#include <string>
#include <iostream>
using namespace std;

// Declare variables 
int hour = 23;
int minute = 59;
int second = 59;

// Accessor and Mutators for Hour, Minute, and Second
void setHour(int newHour) {
	hour = newHour;
}

int getHour() {
	return hour;
}

void setMinute(int newMinute) {
	minute = newMinute;
}

int getMinute() {
	return minute;
}

void setSecond(int newSecond) {
	second = newSecond;
}

int getSecond() {
	return second;
}

// Formats output as two digits
string twoDigitString(unsigned int n) {

	// Declare variables
	string doubleDigit = "";

	// Numbers from 0 to 9 need a "0" tacked onto the front of the string representation of the number
	if (n < 10) {
		doubleDigit += "0";
	}
	// Add 0 to the string
	doubleDigit += to_string(n);

	// Return the two digit string representation of n
	return doubleDigit;

// End of twoDigitString
}

// Repeats a string formatting in program output
string nCharString(size_t n, char c) {

	// Declares variables
	string symbols = "";

	// For every string length adds a char c
	for (size_t i = 0; i < n; i++) {
		symbols += c;
	}

	// Returns a string of length n, each character a c
	return symbols;

// End of nCharString
}

// Formats 24hr clock
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {

	// Declare variables
	string hour = twoDigitString(h);
	string minute = twoDigitString(m);
	string second = twoDigitString(s);

	// Concat hour, minute, and second
	string clock = hour + ":" + minute + ":" + second;

	// return time as hh:mm:ss
	return clock;

// End of formatTime24
}

// Formats 12hr clock
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {

	// Declare variables
	string time = "";
	string hour = twoDigitString(h);
	string minute = twoDigitString(m);
	string second = twoDigitString(s);

	// If hour is 0, change to 12
	if (h == 0) {
		time += "12:";
	}
	// If hour is more than 12, subtract 12 from hour
	else if (h > 12) {
		time += twoDigitString(h - 12) + ":";
	}
	// If hour is less than 12 keep hour the same
	else {
		time += twoDigitString(h) + ":";

	// End of if statement
	}

	// Add minutes after hour
	time += twoDigitString(m) + ":";
	// Add seconds after minute
	time += twoDigitString(s);

	// If hour is less than 12 set time to A M
	if (h < 12) {
		time += " A M";
	}
	// If hour is more than 12 set time to P M
	else {
		time += " P M";

	// End of if statement
	}

	// Return hh:mm:ss A M or hh:mm:ss P M
	return time;

// End of formatTime12
}

// Function to print option menu
void printMenu() {

	// Displays the menu option
	cout << nCharString(15, ' ') << nCharString(27, '*') << endl;
	cout << nCharString(15, ' ') << "* 1 - Add One Hour " << nCharString(7, ' ') << "*" << endl;
	cout << nCharString(15, ' ') << "* 2 - Add One Minute " << nCharString(5, ' ') << "*" << endl;
	cout << nCharString(15, ' ') << "* 3 - Add One Second " << nCharString(5, ' ') << "*" << endl;
	cout << nCharString(15, ' ') << "* 4 - Exit Program " << nCharString(7, ' ') << "*" << endl;
	cout << nCharString(15, ' ') << nCharString(27, '*') << endl;
	
	  
// End of printMenu
}

// Process user input from the menu choice in the user interface
unsigned int getMenuChoice(unsigned int maxChoice) {	

	// Declare variables
	unsigned int userChoice = 0;
	bool decision = true;

	// Gets menu choice 1 through maxChoice, inclusive
	while (decision) {
		cin >> userChoice;

		// If the user's choice is greater or equal than one 
		// or less than maxChoice
		if (userChoice >= 1 || userChoice > maxChoice) {
			decision = false;
		}
		else {
			continue;
		}
	}
	// Returns user's choice
	return userChoice;

// Ends unsigned int getMenuChoice(unsigned int maxChoice) {
}

// Displays the 24hr and 12hr clock 
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {

	// Utilizes nCharString to create "*" & spaces
	// Formats time for 12h and 24h
	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
	cout << "*" << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*" << nCharString(3, ' ');
	cout << "*" << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << endl;
	cout << endl;
	cout << "*" << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << "*" << nCharString(3, ' ');
	cout << "*" << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << "*" << endl;
	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;

// End of displayClocks
}

// Function to add an hour
void addOneHour() {

	// Set to add one unless hours is at 24, then set hour to 0
	setHour(getHour() + 1);

	if (getHour() == 24) {
		setHour(0);

	// End of if statement
	}

// Nothing to return, just setHour to the appropriate value
// End of addOneHour
}

// Function to add a minute
void addOneMinute() {

	// Set minute to add one unless minute is at 60, then set minute to 0
	setMinute(getMinute() + 1);
	if (getMinute() == 60) {
		setMinute(0);
		addOneHour();

	// End of if statement
	}

// Nothing to return, just setMinute to the appropriate value and use addOneHour if needed
// End of addOneMinute
}

// Function to add a second
void addOneSecond() {

	// Set second to add one unless minute is at 60, then set minute to 0
	setSecond(getSecond() + 1);

	if (getSecond() == 60) {
		setSecond(0);
		addOneMinute();

	// End of if statement
	}

// Nothing to return, just call setSecond() with the right value and addOneMinute() when needed
// End of addOneSecond
}

// Concat function to group clock, menu, and personal output 
void taskComplete() {

	// Confirms option executed
	// Returns updated clock and displays menu
	displayClocks(hour, minute, second);
	printMenu();
	cout << endl << "Thank you for waiting, task has been executed.";

// End of taskComplete
}

// Main menu function
int main() {

	// Declare Variables
	// Displays the clock and menu option
	int userChoice = 0;
	displayClocks(hour, minute, second);
	printMenu();
	cout << "Please select an option from the Menu above." << endl;

	// While the user option does not equate to 4
	while (userChoice != 4) {
		userChoice = getMenuChoice(4);

		// Switch options
		// Option 1: add hour
		// Option 2: add minute
		// Option 3: add second
		// Option 4: User will exit program
		// Else: Invalid option, ask user to try again
		cout << endl;
		switch (userChoice) {
			case 1:
				addOneHour();
				taskComplete();
				break;
			case 2:
				addOneMinute();
				taskComplete();
				break;
			case 3:
				addOneSecond();
				taskComplete();
				break;
			case 4:
				cout << endl << "You are now exiting the program." << endl;
				cout << "Goodbye." << endl;
				return 0;
			default: 
				displayClocks(hour, minute, second);
				printMenu();
				cout << endl << "*** Error - Invalid request ***" << endl;
				cout << "Please select an option from the Menu above.";
				continue;

		// End of switch
		}
		
		cout << endl << "Please select an option from the Menu above.";
		cout << "\n\n\n";

	// End of while loop
	}

// End of main menu
}