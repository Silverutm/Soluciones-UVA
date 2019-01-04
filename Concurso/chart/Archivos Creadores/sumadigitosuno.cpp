#include <iostream>
#include <string>
using namespace std;

int tabla_35_de_multiplicar[35][15];

int suma_digitos_uno(int num){
	int sum = 0;
	while(num > 0)
	{
		sum += num % 10;
		num /= 10;
	}
	string auxi =  to_string(sum);
	if (auxi.size() > 1)  {return suma_digitos_uno(sum);} 
	else return sum;
}


int main(int argc, char const *argv[])
{
	cout << "short tabla_35_de_multiplicar [30][10] = {" << endl;
	for (int i = 0; i < 30; ++i)
	{
		cout << "{";
		for (int j = 0; j < 10; ++j)
		{
			if (j > 0)
				cout << ", ";
			cout << suma_digitos_uno(i *  j);
		}
		if(i == 30)
			cout << "}" << endl;
		else cout << "}, " << endl;

	}
	cout << "};" << endl;
	return 0;
}