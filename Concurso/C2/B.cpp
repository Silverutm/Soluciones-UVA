#include <iostream>
#include <cstdio>
using namespace std;
int arreglo[300];
int impares[300];
int main()
{
	string s;
	int  contador=0, j=0;
	char i;
	cin>>s;
	char enmedio;
	for (auto c:s)
		++arreglo[c];
	//cout<<s<<endl;
	//return 0;
	for(i='a'; i<='z'; ++i)
		if (arreglo[i]%2)
		{
			impares[contador]=i;			
			++contador;
		}
	int contmedios=contador/2;
	for (j=0; j<contmedios;++j)
	{
		++arreglo[ impares[j] ];
		--arreglo[ impares[contador-j-1] ];
	}

	for (i='a'; i<='z'; ++i)
		for (j=0; j<arreglo[i]/2; ++j)			
			printf("%c", i);

	if (contador%2) {enmedio=impares[contador/2];	
	printf("%c", enmedio);}

	for (i='z'; i>='a'; --i)
		for (j=0; j<arreglo[i]/2; ++j)
			printf("%c", i);
	cout<<endl;
	return 0;
}