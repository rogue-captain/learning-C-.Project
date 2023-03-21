//# learning-C-.Project
//issues using "getline". keep getting error

//Name and Course:
//Sully Erkan-Rijos - CST 113
// 
//Lab # and title:
//Lab 3
//
// Date:
//03/07/2023
//  
//Description (IPO): 
// This program will take a user input of inches
//and group the total inches into yards and feet. It will also take
//the remaining inches and output the remainder.
// 
//Input:
//Input is accomplished via the standard keyboard. 
//Initial Inch variables are input by the user via keyboard.
//  
//Output: 
//The Output of the program information is done via screen. 
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

const int SCREEN_WIDTH = 80;

const char SYMBOL = '*';

const double DAY_R8 = 0.1;
const double NIGHT_R8 = 0.25;



int main(void)
{
	//declare variables
	ifstream inputFile1;
	ifstream inputFile2;
	ofstream outputFile;

	string name;

	int centerWidth;
	int num;
	int phone;
	int dayMinutes;
	int nightMinutes;

	double totalCost;
	double totalFamilyCost;


	//initialize totals(ACCUMULATOR)
	phone = 0;
	totalCost = 0.0;


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
	cin >> num;

	//----------
	//open output file
	outputFile.open("Ex4Out.txt");

	//conditional input for file selection
	if (num == 1) 
	{
		//open data file 1
		inputFile1.open("Ex4-1.txt");
		cout << "Ex4-1.txt successfully opened." << endl;
	}
	else if (num == 2) 
	{
		//open data file 2
		inputFile2.open("Ex4-2.txt");
		cout << "Ex4-2.txt successfully opened." << endl;
	}

	else 
	{
	cout << "you have entered an invalid file number and the program terminated" << endl;
	}

	//file open verification 
	if (inputFile1.is_open())
	{
		cout << "1 opened verified" << endl;
	}
	if (inputFile2.is_open())
	{
		cout << "2 opened verified" << endl;
	}


//output data to OUTPUT file
	//output program heading
	//divider
	outputFile << setfill(SYMBOL) << setw(SCREEN_WIDTH) 
		       << ' ' << setfill(' ') << endl;
	outputFile << PROGRAMMER << endl;
	outputFile << CLASS << endl;
	//divider
	outputFile << setfill(SYMBOL) << setw(SCREEN_WIDTH) 
			   << ' ' << setfill(' ') << endl;
	outputFile << setw(8) << "Phone" << setw(6) << "Name" << setw(6) << "Day" 
			   << setw(8) << "Night" << setw(8) << "Total" << endl;
	outputFile << setw(20) << "Minutes" << setw(8) << "Minutes" << "Cost" << endl;

	 

	
	
	
	
	//close input and output files
	inputFile1.close();
	inputFile2.close();
	outputFile.close();

	return 0;
}

