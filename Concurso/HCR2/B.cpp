#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#define MAX  256 // maximum characters
#define MAX_log  10000000000
#define MIN_log  1000000000


using namespace std;

struct Access // define struct
{
	// variables needed
	char userName[MAX];
	char Filename[MAX];
	double log;

	string array;
}; 

			 // Identifiers to avoid errors
void Display(string File, double logEntry, double logOut, Access read);
void readFile(string File);
void parseFile(string File, Access read);

/****************************************************************
*readFile()Will prompt the user for the file name and open it, if
*           the file does not exist finish the program, or if it
*           exist, ask the login and logout time and send the info
*           to display.
*****************************************************************/
void readFile(string File) throw ()
{
	// declare the variables for this function
	Access read; // struct variable to send the info
	double logEntry; // entry time or login
	double logOut; // logout time

				   // cout the question
	cout << "Enter the access record file: "; // the Testfile is test.txt

	cin >> File;     // prompt for the name

					 //Declare variables for the file
	ifstream fin(File);

	if (fin.fail()) // contitional if the file fails
	{
		cout << "Unable to read the file from "
			<< File
			<< endl;
		return; //finish the program
	}

	stringstream ss;
	ss.str(File);
	ss >> read.Filename;
	ss >> read.userName;
	ss >> read.log;

	try {
		parseFile(File, read);
	}
	catch (string error)
	{
		cout << "Error parsing line:  " << error;
	}
	stringstream flujo;
	flujo << 123312;
	string cadena;
	flujo >> cadena;

	cout << endl;
	cout << "Enter the start time: "; //questions for the time in
	cin >> logEntry;
	cout << "Enter the end time: "; //questions for the time out
	cin >> logOut;
	cout << endl;
	
	
	


	Display(File, logEntry, logOut, read); // sending the paramenters
										   // to display
	fin.close();   // dont forget to close the file
}

/****************************************************************
*Display()Will put in the screen the format for the file used and
*         set the names and logs and files to display
*****************************************************************/
void Display(string File, double logEntry, double logOut, Access read)
{
	ifstream fin(File); // declare the variable for the file



						// show the results
	cout << "The following records match your criteria:" << endl;
	cout << endl;

	// disign of the output
	cout << "      Timestamp                File                User" << endl
		<< "--------------- ------------------- -------------------" << endl;
	// loop to display the file info

	while (fin >> read.Filename >> read.userName >> read.log)
	{


		if (logEntry <= read.log && logOut >= read.log) //if the info from file
												// are in between login and logout
		{
			


			// display the info from file
			cout << setw(15) << read.log 
				 << setw(20) << read.Filename
				 << setw(20) << read.userName 
				 << endl;
		}
		else // if not do nothing
		{
		}

	}
	cout << "End of records" << endl; // display the end of the file
	return;  // finish
}
void parseFile(string File, Access read) throw (string)
{
	stringstream ss;

	while( ss >> read.Filename >> read.userName >> read.log);
	{
		for (int i = 0; i >= MAX; i++)
		{
			if (ss.fail())
			{
			

			}

			i++;

		}


	}
	



	





}






/**********************************************************************
*Main()will be a simple driver program to hold the format for the numbers
*      and to call readfile.
***********************************************************************/
int main()
{

	cout.setf(ios::fixed); // no scientific notation
	cout.precision(0);     // no decimal points

	string File;
	
	
		readFile(File);
	


	return 0;
}