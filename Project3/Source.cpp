/*
*  Winnie Kwong
*  Professor Foster
*  CS-210 - Programming Languages
*  7-3 Project Three Submission
*  Displaying frequency list of item(s) purchased
*  April 15th, 2023
*/

/*
 * Library includes input/output stream,
 * read datafile, stores sequence of letters,
 * container to store key-value pairs, 
 * character handling functions, and identifiers
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

// Declares SENTINEL as the last option in menu option
const int SENTINEL = 4;


// Data type that has all data member and functions
class produceCounter {

/* 
 * Members accessible from any function
 * Functions include reading input file, display menu, 
 * getting selection, processing selected section,
 * and exit word.
 */
public:
	void downloadFrequencyData();
	void readProduceFile();
	void displayMenu();
	int getSelection();
	void processSelection(int);

/* 
 * Members accessible within class
 * Includes maps to impliment frequency
 * Functions include searching product, frequency list, and histogram
 */
private:
	map<string, int> produceFrequency;
	void searchProduce();
	void frequencyList();
	void histogram();

};

// Downloads a copy of the frequency into a different file, then closes file
void produceCounter::downloadFrequencyData() {
	// Output file stream
	ofstream outFS;

	// Creates a frequency data
	outFS.open("frequency.dat");

	// Creates frequency list from start the end of file
	for (auto produce : produceFrequency) {
		outFS << produce.first << " " << produce.second << endl;
	}

	outFS.close();

// End of downloadFrequencyData
}

// Function to open, read, and close input file
void produceCounter::readProduceFile() {

	ifstream dataFile("CS210_Project_Three_Input_File.txt");
	string produce;

	// Shows how many times a produce appears in the file
	while (dataFile >> produce) {
		produceFrequency[produce]++;
	}

	dataFile.close();

// End of readProduceFile
}

// Function code block to create a menu
void produceCounter::displayMenu() {
	cout << "Main menu" << endl;
	cout << "Option 1: Frequency of one specific produce purchased" << endl;
	cout << "Option 2: List of all produce purchased" << endl;
	cout << "Option 3: Histogram of all produce purchased" << endl;
	cout << "Option " << SENTINEL << ": Exit program" << endl << endl;

// End of displayMenu funtion
}

// Function code block to get selection
int produceCounter::getSelection()
{
	// Creates integer and initalize to 0
	// set boolean function to true 
	// Set exception mask for cin stream
	int selection = 0;
	bool needSelection = true;
	cin.exceptions(ios::failbit);

	// Ask user for option choice
	// If user chooose other, informs user to try again
	// Includes input validation to only accept options 1 -> SENTINEL
	do
	{
		// Notifies user to choose and option
		// Promots user selction
		try {
			cout << "Please choose selection between 1 to " << SENTINEL << endl;
			cin >> selection;
			needSelection = ((selection < 1) || (selection > SENTINEL));

		} // End of try

		// Executes if selection is not between 1 -> SENTINEL
		// Clears error flags
		// Extracts keyboard buffer 
		catch (ios::failure&) {
				cin.clear();
				cin.ignore(100, '\n');

		// End of catch
		}
	// end of do
	}

	// When boolean is true, returns selection
	while (needSelection);

return selection;
// End of getSelection
} 

// Function to process user selection
void produceCounter::processSelection(int selection)
{
	/* 
	 * Switch function to return user selection
	 * 1) Searching product
	 * 2) frequency list
	 * 3) histogram
	 * default - close program
	*/
	switch (selection) {
	case 1:
		cout << "Which item are you looking for?" << endl;
		searchProduce();
		break;
	case 2:
		cout << "Now displaying total amount of each produce purchased." << endl << endl;
		frequencyList();
		break;
	case 3:
		cout << "Now displaying histogram of each produce purchased." << endl << endl;
		histogram();
		break;
	default:
		cout << "Now closing program, goodbye." << endl;
		break;

	// End of switch
	}

// End of processSelection
} 

// Function to search produce
void produceCounter::searchProduce() {

	/* 
	 * Declares produce for user input
	 * Prompts user to input produce
	 * Force uppercases prompt to execute program
	*/
	string produce;
	cin >> produce;
	produce[0] = toupper(produce[0]);

	/* 
	 * Outputs invalid if its not in the list
	 * If produce is in the list, it will display amount purchased
	*/ 
	if (produceFrequency.find(produce) == produceFrequency.end()) {
		cout << produce << " does not exist in the list" << endl << endl;
	}
	else {
		cout << produce << " was purchased " << produceFrequency[produce] << " time(s)." << endl << endl;
	}

// End of searchProduce
}

// Function to see how many times produce was purchased
void produceCounter::frequencyList() {

	// Auto const combined with produce will display all strings in the data file
	for (auto const& produce : produceFrequency) {
		cout << produce.first << " " << produce.second << endl;
	}

	// Adds new line to separate from menu option after frequencyList executes
	cout << endl;

// End of frequency list
}

// Function to see histogram version of how many times produce was purchased
void produceCounter::histogram() {

	// Auto const combined with produce will display all strings in the data file
	// Per every produce on list, counter displays +1 asterisks (*)
	for (auto const& produce : produceFrequency) {
		cout << produce.first << " ";
		for (int i = 0; i < produce.second; i++) {
			cout << "*";
		}
		cout << endl;
	}
	// Adds new line to separate from menu option after histogram executes
	cout << endl;

// End of histogram
}

// Main function of program
int main() {

	// Declares selection to intialize at 0
	int selection = 0;

	cout << "Backing up accumulated data into frequency.dat file" << endl << endl;

	/*
	 * Uses public class to read data file, display menu,
	 * download puchased information into a separete file,
	 * retrieve selection, and process the selection
	 * only while SENTINEL is not chosen
	*/
	do {
		produceCounter produceCounter;
		produceCounter.readProduceFile();
		produceCounter.downloadFrequencyData();
		produceCounter.displayMenu();
		selection = produceCounter.getSelection();
		cout << selection << endl;
		produceCounter.processSelection(selection);
	} while (selection != SENTINEL);

	// Exits program
	return 0;

	// End of main function
}