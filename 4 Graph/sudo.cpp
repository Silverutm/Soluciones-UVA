//#include <conio.h>  // se puede quitar
//#include "stdafx.h" // se puede quitar
/***********************************************************************
* Program:
*    Project 12, Sudoku Project
*    Brother Ellsworth, CS124
* Author:
*    Isaac David Sanchez Marquez
* Summary:
*    This project will read a file that has a built in Getfilename function
*    it will read it into an array and then, separate it in col, and row
*    next, we build a writeFile function, that will read the actual array
*    and then export it into a file we want to, then we built interact
*    it will prompt the user for a series of options, like ?, E, D, S,
*    we tried to use the advanced conditional but it did not work as we
*    expect it, and we switched back to IF, then according to the option
*    typed we will call different functions to perform an operation
*    but if we type Q it will call write file and close the program.
*    then we created EditSquare that is conbined with getcoordinates
*    it will first ask for the coordinates and then change all the input
*    to uppercase and make the changes on the board if it is permited.
*    then, we created Display, thats a copy from the tic tac toe assignment
*    eassy to do, then we created displayoptions, and finally main.*
************************************************************************/
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
using namespace std;
void displayOptions(char board[][9]); // functions that need to be on top to avoid
void displayBoard(char board[][9]);   // compile errors
void editSquare(char board[][9]);


/**********************************************************************
*readFile()this function will work with the file name, it will
*          open the file and then read the info and write it into
*          a new array and send it to display with a double for loop
*          this function was convined with getfilename and readfile.
*             (taken from my previous tic tac toe assignment)
***********************************************************************/
void readFile(char board[][9])
{
	char filename[256];

	ifstream fin; // open the file
				  // cout the question
	cout << "Where is your board located? ";
	// prompt for the name
	cin >> filename;


	fin.open(filename);
	if (fin.fail())  // if the file cant be found
	{
		cout << "Input file opening failed.\n"; // cout error
		return; // nothing, its a void
	}
	//double for loop for 
	for (int j = 0; j < 9; j++) // the 2D array, row, and col
		for (int i = 0; i < 9; i++)
		{
			fin >> board[j][i]; // write the data to a new 2D array
			if (board[j][i] == '0') // while writting, change the 0's to spaces
			{
				board[j][i] = ' ';
			}
		}
	fin.close(); // Dont forget to close
}

/****************************************************************
* writeFile()it will ask the user for the new file to write info
*            and then it will write the info back in a new file
*            my previews IF statement form the abobe function
*            helped me to rewrite the file with almost the same
*            values, it was finnally modified to output the values
*            in the rigth way. (modified from tic tac toe)
*****************************************************************/
void writeFile(char board[][9])
{

	ofstream fout; // file out or to write
	char newFile[256]; // variable we are using for new file

					   // prompt for new file
	cout << "What file would you like to write your board to: ";
	cin >> newFile;                       // new file name

	fout.open(newFile); // attempt to write begins.
	if (fout.fail()) // if it fails
	{
		cout << "Output file opening failed." << endl; // cout error
		return;  // return nothing, its a void
	}
	else // if it does not fails
		cout << "Board written successfully" << endl; ; // cout perfecto

														// previous double for loop but backwards
	for (int j = 0; j < 9; j++) // row, and col
	{
		for (int i = 0; i < 9; i++)
		{

			if (board[j][i] == ' ')//if filename row[0]col[i that changes] == " "
			{
				board[j][i] = '0';// change it to a "."
			}
			fout << board[j][i] << ' '; // spaces for the row

			if (i == 😎
			{
				fout;
			}
		}
	}

	fout.close();  // close out file
	exit(1); // serious problem!!! I couldn't make the code close without using
			 // the #include <stdlib.h> library, this makes the test bed act weird
			 // the test bed displays "Program ended with error: 1." i need 
			 //feedback please!!
	return;
}

/**********************************************************************
*interact()interact will prompt the user with the menu of options and
*          depending on the input, the program will perform a unique
*          action, like display write interact again or edit the array
***********************************************************************/
int interact(char board[][9])
{
	char prompt; // variable we will use for the menu

	cout << "> "; // nesessary
	cin >> prompt; // get the options

	toupper(prompt); // this will change everything to uppercase

					 // do while loop starts 
	do
	{
		if (prompt == 'e' || prompt == 'E') // just in case e or E
			editSquare(board);         // will call edit square
		else if (prompt == '?')        // if its not an E then check ?
		{
			displayOptions(board);    // it will call the menu again to the screen
			cout << endl;            // new line "style"
			cout << endl;           // new line "style"
			interact(board);        // call interact again, and start over
			return 0;
		}
		else if (prompt == 'd' || prompt == 'D') // if it is not E or ? then check D
			displayBoard(board);                // if D then Call Display


		else if (prompt == 's' || prompt == 'S') // S is not working yet
		//	showPossibleValues(board);;
			;

		/*********************************************************************
		I tried to use  advance contitional but it didnt work, i included my code
		Just to receive feedbak, please, thank you
		**********************************************************************
		switch (toupper(prompt))
		{
		case '?':
		displayOptions();
		break;
		case 'D':
		displayBoard(board);
		break;
		case 'E':
		editSquare(board);
		break;
		case 'S':
		break;
		}
		***/


		// end of while loop if prompt == Q
	} while (prompt != 'Q');

	// if prompt is Q or q then call wrriteFile
	if (prompt == 'Q' || prompt == 'q')
	{
		writeFile(board);
		return 0;
	}
	// if prompt not equals to any of the menu values, cout error
	else if (prompt != '?' || prompt != 'D' || prompt != 'E' || prompt != 'S')
	{
		cout << "ERROR: Invalid command" << endl;
		return 0;
	}
	return 0; // end of the function
}


/**********************************************************************
*editSquare()will change or add values to the array, it was very diifficult
*            to understand how to inplement it, but Zachary suggested us
*            to convine the coordinates with edit squares, and it worked
*            once the function gets the prompt from the user it will send
*            the values to the array
***********************************************************************/
void editSquare(char board[][9])
{
	char topLetter; // the col variable
	int sideNumber; // the row variable
	char newinput; // new number of the array as a char because board is a char
	int possiblenum[10] = { 0, 1, 2, 3, 4, 5 , 6, 7, 8, 9 }; /************************************************/


	cout << "What are the coordinates of the square: "; // question
	cin >> topLetter >> sideNumber;                 // and prompt

	topLetter = toupper(topLetter); // this will change the letters to Uppercase

	if (board[topLetter - 65][sideNumber - 1] != ' ') // if the array isnt free
	{                           // display that it is already taken
		cout << "ERROR: Square " << "'" << topLetter << sideNumber
			<< "'" << " is filled" << endl;
		cout << endl; // too many spaces for "style"
		interact(board); // call interact again
	}
	else // if the array is free, then ask for the new value
	{
		cout << "What is the value at " << "'" << topLetter << sideNumber << "': ";
		cin >> newinput; // the new value prompt



						 //Switch values in the top letters, tjhey will be used as coordinates to 
						 // get the new values for the array
		switch (topLetter)
		{
		case 'A':  // A equals 0
			topLetter = 0;
			break;
		case 'B':  // B equals 1
			topLetter = 1;
			break;
		case 'C':  // C equals 2
			topLetter = 2;
			break;
		case 'D': // D equals 3
			topLetter = 3;
			break;
		case 'E': // E equals 4
			topLetter = 4;
			break;
		case 'F': // F equals 5
			topLetter = 5;
			break;
		case 'G': // G equals 6
			topLetter = 6;
			break;
		case 'H': // H equals 7
			topLetter = 7;
			break;
		case 'I': // I Equals 8
			topLetter = 8;
			break;
		}






	}
	cout << endl; // cout newline Style
	board[sideNumber - 1][topLetter] = newinput; // this will do the trick
	interact(board); // call the interact function again
	return;
}


/**********************************************************************
*displayBoard()it similar to my tic tac toe function, it will cout
*              the array one by one in their respective places and editSquares
*              will put the new values acording to our input, simple
***********************************************************************/
void displayBoard(char board[][9])
{
	cout << "   A B C D E F G H I" << endl; // top row 





	cout << "1"; // row 1

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
		
	if (board[i][j] > 0)
		//A1                 //B1                  //C1
		cout << "  " << "\E[22;32m" << board[i][j] << "\E[0m" << " " << "\E[22;32m" << board[i][j] << "\E[0m" << " " << board[i][j]
		<< "|"
		//D1                //E1                   //F1
		<< board[i][j] << " " << board[i][j] << " " << board[i][j]
		<< "|"
		//G1                 // H1                  //I1
		<< board[i][j] << " " << board[i][j] << " " << board[i][j];
	cout << endl;
        }


	cout << "2" // row 2
				//A2                  //B2                  //C2
		<< "  " << board[1][0] << " " << board[1][1] << " " << board[1][2]
		<< "|"
		//D2                  //E2                  //F2
		<< board[1][3] << " " << board[1][4] << " " << board[1][5]
		<< "|"
		//G2                 // H2                  //I2
		<< board[1][6] << " " << board[1][7] << " " << board[1][8];
	cout << endl;



	cout << "3" // row 3
				//A3                  //B3                  //C3
		<< "  " << board[2][0] << " " << board[2][1] << " " << board[2][2]
		<< "|"
		//D3                  //E3                  //F3
		<< board[2][3] << " " << board[2][4] << " " << board[2][5]
		<< "|"
		//G3                 // H3                  //I3
		<< board[2][6] << " " << board[2][7] << " " << board[2][8];
	cout << endl;

	cout << "   -----+-----+-----" << endl;


	cout << "4" // row 4
				//A4                  //B4                  //C4
		<< "  " << board[3][0] << " " << board[3][1] << " " << board[3][2]
		<< "|"
		//D4                  //E4                  //F4
		<< board[3][3] << " " << board[3][4] << " " << board[3][5]
		<< "|"
		//G4                 // H4                  //I4
		<< board[3][6] << " " << board[3][7] << " " << board[3][8];
	cout << endl;


	cout << "5" // row 5
				//A5                  //B5                  //C5
		<< "  " << board[4][0] << " " << board[4][1] << " " << board[4][2]
		<< "|"
		//D5                  //E5                  //F5
		<< board[4][3] << " " << board[4][4] << " " << board[4][5]
		<< "|"
		//G5                 // H5                  //I5
		<< board[4][6] << " " << board[4][7] << " " << board[4][8];
	cout << endl;

	cout << "6" // row 6
				//A6                  //B6                  //C6
		<< "  " << board[5][0] << " " << board[5][1] << " " << board[5][2]
		<< "|"
		//D6                  //E6                  //F6
		<< board[5][3] << " " << board[5][4] << " " << board[5][5]
		<< "|"
		//G6                 // H6                  //I6
		<< board[5][6] << " " << board[5][7] << " " << board[5][8];
	cout << endl;

	cout << "   -----+-----+-----" << endl;

	cout << "7" // row 7
				//A7                  //B7                  //C7
		<< "  " << board[6][0] << " " << board[6][1] << " " << board[6][2]
		<< "|"
		//D7                  //E7                  //F7
		<< board[6][3] << " " << board[6][4] << " " << board[6][5]
		<< "|"
		//G7                 // H7                  //I7
		<< board[6][6] << " " << board[6][7] << " " << board[6][8];
	cout << endl;


	cout << "8" // row 8
				//A8                  //B8                  //C8
		<< "  " << board[7][0] << " " << board[7][1] << " " << board[7][2]
		<< "|"
		//D8                  //E8                  //F8
		<< board[7][3] << " " << board[7][4] << " " << board[7][5]
		<< "|"
		//G8                 // H8                  //I8
		<< board[7][6] << " " << board[7][7] << " " << board[7][8];
	cout << endl;

	cout << "9" // row 9
				//A9                  //B9                  //C9
		<< "  " << board[8][0] << " " << board[8][1] << " " << board[8][2]
		<< "|"
		//D9                  //E9                  //F9
		<< board[8][3] << " " << board[8][4] << " " << board[8][5]
		<< "|"
		//G9                 // H9                  //I9
		<< board[8][6] << " " << board[8][7] << " " << board[8][8];

	cout << endl; // style spaces 
	cout << endl;
	interact(board); // call interact again
}


/**********************************************************************
void displayOptions()Simple function, this is the menu, interact will
*                    get the values needed
***********************************************************************/
void displayOptions(char board[][9])
{

	cout << "Options:" << endl// the options  and spaces needed
		<< "   ?  Show these instructions" << endl
		<< "   D  Display the board" << endl
		<< "   E  Edit one square" << endl
		<< "   S  Show the possible values for a square" << endl
		<< "   Q  Save and Quit" << endl;


	return; // return nothing, its a void.

}








/**********************************************************************
*Main()simple Driver program to display simple functions
***********************************************************************/
int main()
{
	char board[9][9]; // Variable to store the numbers

	readFile(board); // we call multiple functions to start working
	displayOptions(board);
	cout << endl;
	displayBoard(board);


	cin.get();           // se puede quitar
	cin.ignore();        // se puede quitar



	return 0;
}