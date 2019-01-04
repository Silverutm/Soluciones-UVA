/***********************************************************************
* Program:
*    Checkpoint 02b, Complex Numbers
*    Brother Walker, CS165
* Author:
*    Isaac David Sanchez Marquez
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;



// TODO: Define your Complex struct here
struct Complex

{
	double real = 0;
	double imaginary = 0;
	
} c1, c2;

Complex addComplex(const Complex & c1, const Complex &c2);

// TODO: Add your prompt function here
void prompt(Complex &capture)
{
	cout << "Real: ";
	cin >> capture.real;

	cout << "Imaginary: ";
	cin >> capture.imaginary;


	return ;
}


// TODO: Add your display function here
void display(Complex sum)
{
	
	cout << sum.real << " + " << sum.imaginary << "i" ;

	return;
}


/**********************************************************************
* Function: addComplex
* Purpose: Adds two complex numbers together and returns the sum.
***********************************************************************/
Complex addComplex(const Complex &c1, const Complex &c2)
{
	// TODO: Fill in the body of the add function
		Complex sum;
	
	sum.real += c1.real + c2.real;
	sum.imaginary += c1.imaginary + c2.imaginary;
	
	
	return sum;
}


/**********************************************************************
* Function: main
* Purpose: This is the entry point and driver for the program.
***********************************************************************/
int main()
{
	// Declare two Complex objects, c1 and c2
	Complex c1;
	Complex c2;
	// Call your prompt function twice to fill in c1, and c2
	prompt(c1);
	prompt(c2);

	// Declare another Complex for the sum
	Complex sum;
	

	// Call the addComplex function, putting the result in sum;
	//addComplex(c1, c2);

	cout << "\nThe sum is: ";
	display(sum);
	cout << endl;


	cin.get();           // se puede quitar
	cin.ignore();        // se puede quitar


	return 0;
}