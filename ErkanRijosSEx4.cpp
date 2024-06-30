//Name and Course:
//Sully Erkan-Rijos - CST 113
// comments:
// 
//Lab # and title:
//Lab 4
//
// Date:
//03/21/2023
//  
//Description (IPO): 
// This program will prompt user to select a file. 
// Then take data of the string and double type from an 
// external file and process the data. it will then
// take the output data into a seperate, output file. 
// 
//Input:
//Input is initially from user to select a file. then all 
// of the input data is streamed in from the selected external file.
//  
//Output: 
//The Output of the program information is output to a dedicated
// output file to collect data.
// 
//-------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//constants
const string PROGRAMMER = "Sully Erkan-Rijos";
const string CLASS = "CST 113 - Exercise 4";
const string EXERCISE = "CELL PHONE BILL";

const int SCREEN_WIDTH = 80;

const char SYMBOL = '*';

const double DAY_R8 = 0.1;
const double NIGHT_R8 = 0.25;



int main(void)
{
	//declare variables
	ifstream inputFile;
	ofstream outputFile;

	string name;
	string nameFile; 

	int centerWidth;
	int numFile;
	int phone;
	int dayMinutes;
	int nightMinutes;

	double totalCost;
	double totalFamilyCost;


	//initialize totals(ACCUMULATOR)
	phone = 0;
	totalFamilyCost = 0.0;


	//----------User prompt	
	//Prompt user to select File
	
	//divider
	cout << setfill(SYMBOL) << setw(SCREEN_WIDTH)
		<< ' ' << setfill(' ') << endl;
	cout << "Select from these two file names: " << endl;
	cout << "1:   Ex4-1.txt" << endl;
	cout << "2:   Ex4-2.txt" << endl;
	
	//divider
	cout << setfill(SYMBOL) << setw(SCREEN_WIDTH)
		<< ' ' << setfill(' ') << endl;
	//prompt user to select file 1 or 2
	cout << "enter the number of the input file: ";
	cin >> numFile;
	
	
	//----------
	//open output file
	outputFile.open("Ex4Out.txt");

	//conditional "or" input for file selection
	if (numFile == 1 || numFile == 2)
	{
		if (numFile == 1)
			//open data file 1
		{
			nameFile = "Ex4-1.txt";
		}

		else
		{
			//open data file 2
			nameFile = ("Ex4-2.txt");
		}

		//Output the success message to screen
		inputFile.open(nameFile);
		cout << nameFile << "successfully opened.";
	}

	else
	{
		//output error message to screen 
		cout << "you have entered an invalid file number and the program terminated" << endl;
	}
		
		

	//----------output data to OUTPUT file
	//set up floating point output to the output file 
	outputFile << fixed << setprecision(2);
	

	//----------output program heading
	//divider
	outputFile << setfill(SYMBOL) << setw(SCREEN_WIDTH) 
		       << ' ' << setfill(' ') << endl;
	
	//center class information heading
	centerWidth = (SCREEN_WIDTH + PROGRAMMER.length()) / 2;
	outputFile << setw(centerWidth) << PROGRAMMER << endl;
	
	//center class information heading
	centerWidth = (SCREEN_WIDTH + CLASS.length()) / 2;
	outputFile << setw(centerWidth) << CLASS << endl;
	
	//center class information heading
	centerWidth = (SCREEN_WIDTH + EXERCISE.length()) / 2;
	outputFile << setw(centerWidth) << EXERCISE << endl; 
	
	//divider
	outputFile << setfill(SYMBOL) << setw(SCREEN_WIDTH) 
			   << ' ' << setfill(' ') << endl;
	
	//output a heading to the output file
	outputFile << setw(10) << "Phone" << setw(20) << "Name" << setw(15) << "Day" 
			   << setw(15) << "Night" << setw(15) << "Total" << endl;
	outputFile << setw(45) << "Minutes" << setw(15) << "Minutes" << setw(15) << "Cost" << endl;

	
	//----------1st line of data -----------	
	
	//count phone users
	phone++;

	//extract data for first line
	getline(inputFile, name);
	inputFile >> dayMinutes >> nightMinutes;

	//calculate total phone minutes
	totalCost = (DAY_R8 * dayMinutes) + (NIGHT_R8 * nightMinutes);

	//Accumulate total family cost
	totalFamilyCost += totalCost;

	//divider
	outputFile << setfill(SYMBOL) << setw(SCREEN_WIDTH)
			   << ' ' << setfill(' ') << endl;

	//output phone user info to output file
	outputFile << setw(10) << phone << setw(20) << name 
			   << setw(15) << dayMinutes << setw(15) << nightMinutes 
			   << setw(15) << totalCost << endl;


	//----------2nd Line of data ---------
	//count phone users
	phone++;

	//ignore first line from input file
	inputFile.ignore(100, '\n');

	//extract data for second line
	getline(inputFile, name);
	inputFile >> dayMinutes >> nightMinutes;

	//calculate total phone minutes
	totalCost = (DAY_R8 * dayMinutes) + (NIGHT_R8 * nightMinutes);

	//Accumulate total family cost
	totalFamilyCost += totalCost;

	//output info 
	outputFile << setw(10) << phone << setw(20) << name
			   << setw(15) << dayMinutes << setw(15) << nightMinutes
			   << setw(15) << totalCost << endl;


	//-----------3rd line of data----------
	//count phone users
	phone++;

	//ignore next line from input file
	inputFile.ignore(100, '\n');

	//extract data for third line
	getline(inputFile, name);
	inputFile >> dayMinutes >> nightMinutes;

	//calculate total phone minutes
	totalCost = (DAY_R8 * dayMinutes) + (NIGHT_R8 * nightMinutes);

	//Accumulate total family cost
	totalFamilyCost += totalCost;

	//output info 
	outputFile << setw(10) << phone << setw(20) << name
			   << setw(15) << dayMinutes << setw(15) << nightMinutes
			   << setw(15) << totalCost << endl;


	//----------calculate TOTAL	---------
	//divider
	outputFile << setfill(SYMBOL) << setw(SCREEN_WIDTH)
			   << ' ' << setfill(' ') << endl;
	outputFile << "Total Family cost: " << setw(56) << totalFamilyCost << endl;
	
	//close input and output files
	inputFile.close();
	outputFile.close();

	return 0;
}
