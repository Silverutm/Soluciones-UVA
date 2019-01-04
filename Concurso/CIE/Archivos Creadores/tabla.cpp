#include <iostream>
#include <string>
using namespace std;

int tabla_mult[65][40];
int tabla_03_residuo[255];
int tabla_04_residuo[3805];
int decena_04[105];
int decimal_04[105];
int tabla_06_residuo[2705];



int tabla_07_residuo[100];
int tabla_08_residuo[100];

int tabla_35_de_multiplicar[35][10];


int main(int argc, char const *argv[])

{
	//60, 25
	for (int i = '0'; i <= '9'; ++i)
		for (int j = 0; j < 40; ++j)
			tabla_mult[i][j] = (i - '0') * j;
	//imprimir

	
/*cout << "short tabla_03_de_multiplicar [60][40] = {" << endl;

	for (int i = 0; i < 60; ++i)
	{
		cout << "{ ";
		bool primero =  true;
		for (int j = 0; j < 40; ++j)
		{
			if(!primero) cout << ", ";  
			j == 0 ? primero =  false : false;
			cout << tabla_mult[i][j];
		}
		if (i == 59) cout << "} " << endl;
		else cout << "}," << endl;
	}
	cout << "};" << endl;

return 0;*/////////////////////
	cout << "short tabla_03_de_residuo	 [250] = {" << endl;


	for (int i = 0; i < 250; ++i)
	{
		tabla_03_residuo[i] = 7 - i % 7;
		if (i)
			cout << ", " << tabla_03_residuo[i];
		else cout << tabla_03_residuo[i];

	}	
	cout << "};" << endl;

	cout << "short tabla_04_de_residuo [3800] = {" << endl;


	for (int i = 0; i < 3800; ++i)
	{
		tabla_04_residuo[i] = (i + 330) % 97 + 1;
		if (i)
			cout << ", " << tabla_04_residuo[i];
		else cout << tabla_04_residuo[i];

	}	
	cout << "};" << endl;




	cout << "short decena_04[100] = {" << endl;


	for (int i = 0; i < 100; ++i)
	{
		decena_04[i] = i / 10;
		if (i)
			cout << ", " << decena_04[i];
		else cout << decena_04[i];

	}	
	cout << "};" << endl;

	cout << "short decimal_04[100] = {" << endl;


	for (int i = 0; i < 100; ++i)
	{
		decimal_04[i] = i % 10;
		if (i)
			cout << ", " << decimal_04[i];
		else cout << decimal_04[i];

	}	
	cout << "};" << endl;

	cout << endl << endl;
	int x = (1 * 23 + 2 * 29 + 3 * 31 + 4 * 37) + 9 * (23 + 29 + 31 + 37);
	cout << "short val_06= " << x << "; " << endl;



	cout << "short tabla_06_residuo[4100] = {" << endl;


	for (int i = 0; i < 4100; ++i)
	{
		tabla_06_residuo[i] = 99 - i % 97;
		if (i)
			cout << ", " << tabla_06_residuo[i];
		else cout << tabla_06_residuo[i];

	}	
	cout << "};" << endl;




	cout << "short tabla_07_residuo[] = {" << endl;


	for (int i = 'A'; i <= 'Z'; ++i)
	{
		tabla_07_residuo[i] = i - 'A' + 1;
		if(i == 'A' )cout << tabla_07_residuo[i];
		else cout << ", " << tabla_07_residuo[i];

	}	
	cout << "};" << endl;

	cout << "short tabla_08_residuo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8}; " << endl;	


//int tabla_30x10 [30][10]

	
	return 0;
}