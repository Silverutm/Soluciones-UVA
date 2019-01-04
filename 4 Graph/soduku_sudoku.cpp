//#include <conio.h>  // se puede quitar
//#include "stdafx.h" // se puede quitar
#include <cassert>
#include <fstream>
#include <set>


/***********************************************************************
* Program:
*    Assignment 44, Search Speed
*    Brother Ellsworth, CS124
* Author:
*    Isaac David Sanchez Marquez
* Summary:
*    This program compares the search speed of the linear search
*    and the binary search.
*
*    Estimated:  0.15 hrs
*    Actual:     3.0 hrs
*      Well the most difficult par was to focus, I got jumped and i'm not
*      focus like I used to, but the most dificult part was to create the
*      code, once I notice that i had to send the array back to the seraches
*      everything started to work.
************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
void displayOptions();
void displayBoard(char board[][9]);
void editSquare(char board[][9]);
void suggestions(char board[][9]);


/**********************************************************************

***********************************************************************/
void readFile(char board[][9])
{
	char filename[256];

	ifstream fin;

	cout << "Where is your board located? ";
	cin >> filename;


	fin.open(filename);
	if (fin.fail())
	{
		cout << "Input file opening failed.\n";
		return;
	}

	for (int j = 0; j < 9; j++) // row, and col
		for (int i = 0; i < 9; i++)
		{
			fin >> board[j][i];
			if (board[j][i] == '0')
			{
				board[j][i] = ' ';
			}
		}
	fin.close(); // Dont forget to close 
}

void suggestions(char board[][9])
{
	char fila, columna;
	cin>>fila>>columna;
	//B2 por ejemplo
	//tu verificas que este dentro de los rangos

	fila = fila - '1'; //convertir a entero
	columna = columna - 'A'; //idem

	set<int> posibles({1,2,3,4,5,6,7,8,9}); //para que uses binary search xD
	//#include <set>
	//si no funciona, usa
	//for (int i = 1; i <= 9; ++i)
	//	posibles.insert(i);

	//eliminar ya elegidos en la columna
	for (int col = 0; col < 9; ++col)
	{
		int n =board[fila][col ] - '0';
		
		if (posibles.find(n)!= posibles.end())
			posibles.erase(n);
	}

	//eliminar ya elegidos en la fila
	for (int reng = 0; reng < 9; ++reng)
	{
		int n =board[reng][columna ] - '0';
		
		if (posibles.find(n)!= posibles.end())
			posibles.erase(n);
	}

	//ahora debemos obtener el cuadrado al que pertenece
	int num_fila = fila/3;
	int num_columna = columna/3;
	//listo

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		{
			int n= board[ num_fila*3 +i ][ num_columna*3 +i ] - '0';
			if (posibles.find(n)!= posibles.end())
			posibles.erase(n);
		}

	for (auto &e: posibles)
		cout<<e<<" ";
	cout<<endl;
}

/****************************************************************
* writeFile()it will ask the user for the new file to write info
*			 and then it will write the info back in a new file
*			 my previews IF statement form the abobe function
*			 helped me to rewrite the file with almost the same
*			 values, it will display it as 1 row. but it works.
*****************************************************************/
void writeFile(char board[][9])
{

	ofstream fout; // file out or to write
	char newFile[256]; // variable we are using for new file

	cout << "What file would you like to write your board to: "; // prompt for new file
	cin >> newFile;                       // new file name

	fout.open(newFile); // attempt to write begins.
	if (fout.fail()) // if it fails
	{
		cout << "Output file opening failed." << endl; // cout error
		return;  // return nothing, its a void
	}
	else // if it does not fails
		cout << "Board written successfully" << endl; // cout perfecto

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

			if (i % 9 == 0)
			{
				fout << endl;
			}
		}
	}

	fout.close();  // close out file

}

/**********************************************************************

***********************************************************************/
void interact(char board[][9])
{
	char prompt;


	do
	{
		cout << endl;
		cout << "> ";
		cin >> prompt;
		if (prompt == 'Q' || prompt == 'q')
		{
			writeFile(board);
			 exit(0);
		}

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
			suggestions(board);
			break;
		//case 'Q':
		//	break;


		default:
			cout << "ERROR: Invalid command";
			break;
		}
	} while (true);
	
	return;
}


void editSquare(char board[][9])
{
	char topLetter;
	int sideNumber;
	char newinput ;
	cout << "What are the coordinates of the square: ";
	cin >> topLetter >> sideNumber;

	topLetter = toupper(topLetter);

		if (board[topLetter - 65][sideNumber - 1] != ' ')
		{
			cout << "ERROR: Square " << "'" << topLetter << sideNumber << "'" << " is filled";
			cout << endl;
			return ;
			//interact(board);
		}
		cout << "What is the value at " << "'" << topLetter << sideNumber << "': ";
		cin >> newinput;

	
		topLetter -= 'A';

			
		cout << endl;
		board[topLetter][sideNumber - 1] = newinput;
		//interact(board);
		return;

}




/**********************************************************************
ready, don't touch it!
***********************************************************************/
void displayBoard(char board[][9])
{
	cout << "   1 2 3 4 5 6 7 8 9" << endl;

	cout << "A"
		<< "  " << board[0][0] << " " << board[0][1] << " " << board[0][2]
		<< "|"
		<< board[0][3] << " " << board[0][4] << " " << board[0][5]
		<< "|"
		<< board[0][6] << " " << board[0][7] << " " << board[0][8];
	cout << endl;



	cout << "B"
		<< "  " << board[1][0] << " " << board[1][1] << " " << board[1][2]
		<< "|"
		<< board[1][3] << " " << board[1][4] << " " << board[1][5]
		<< "|"
		<< board[1][6] << " " << board[1][7] << " " << board[1][8];
	cout << endl;



	cout << "C"
		<< "  " << board[2][0] << " " << board[2][1] << " " << board[2][2]
		<< "|"
		<< board[2][3] << " " << board[2][4] << " " << board[2][5]
		<< "|"
		<< board[2][6] << " " << board[2][7] << " " << board[2][8];
	cout << endl;

	cout << "   -----+-----+-----" << endl;


	cout << "D"
		<< "  " << board[3][0] << " " << board[3][1] << " " << board[3][2]
		<< "|"
		<< board[3][3] << " " << board[3][4] << " " << board[3][5]
		<< "|"
		<< board[3][6] << " " << board[3][7] << " " << board[3][8];
	cout << endl;


	cout << "E"
		<< "  " << board[4][0] << " " << board[4][1] << " " << board[4][2]
		<< "|"
		<< board[4][3] << " " << board[4][4] << " " << board[4][5]
		<< "|"
		<< board[4][6] << " " << board[4][7] << " " << board[4][8];
	cout << endl;

	cout << "F"
		<< "  " << board[5][0] << " " << board[5][1] << " " << board[5][2]
		<< "|"
		<< board[5][3] << " " << board[5][4] << " " << board[5][5]
		<< "|"
		<< board[5][6] << " " << board[5][7] << " " << board[5][8];
	cout << endl;

	cout << "   -----+-----+-----" << endl;

	cout << "G"
		<< "  " << board[6][0] << " " << board[6][1] << " " << board[6][2]
		<< "|"
		<< board[6][3] << " " << board[6][4] << " " << board[6][5]
		<< "|"
		<< board[6][6] << " " << board[6][7] << " " << board[6][8];
	cout << endl;


	cout << "H"
		<< "  " << board[7][0] << " " << board[7][1] << " " << board[7][2]
		<< "|"
		<< board[7][3] << " " << board[7][4] << " " << board[7][5]
		<< "|"
		<< board[7][6] << " " << board[7][7] << " " << board[7][8];
	cout << endl;

	cout << "I"
		<< "  " << board[8][0] << " " << board[8][1] << " " << board[8][2]
		<< "|"
		<< board[8][3] << " " << board[8][4] << " " << board[8][5]
		<< "|"
		<< board[8][6] << " " << board[8][7] << " " << board[8][8];
	cout << endl;

	//interact(board);
}



/**********************************************************************
ready, don't touch it!
***********************************************************************/
void displayOptions()
{
	cout << "Options:" << endl
		<< "   ?  Show these instructions" << endl
		<< "   D  Display the board" << endl
		<< "   E  Edit one square" << endl
		<< "   S  Show the possible values for a square" << endl
		<< "   Q  Save and Quit" << endl;


	return;

}


/**********************************************************************

***********************************************************************/
int main()
{
	char board[9][9];

	readFile(board);
	displayOptions();
	cout << endl;
	displayBoard(board);

	interact(board);





	cin.get();           // se puede quitar
	cin.ignore();        // se puede quitar

	return 0;
}