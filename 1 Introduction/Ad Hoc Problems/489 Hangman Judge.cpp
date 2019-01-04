#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int n, arreglo[300], letras,contador;
	string s1, s2;
	while (cin>>n and ~n)
	{
		cin>>s1>>s2;
		letras=0;
		contador=0;
		memset (arreglo, 0, sizeof arreglo);
		for (auto c:s1)
		{
			if (not arreglo[c])
			{
				arreglo[c]=1;
				++letras;
			}
		}
		//cout<<"Letas "<<letras<<endl;
		for (auto c:s2)
		{
			if (arreglo[c]==-1) continue;
			else if (not arreglo[c] )
			{
				arreglo[c] = -1;
				contador++;
				//cout<<"Error: "<<c<<endl;
			}
			else 
			{
				arreglo[c]=-1;
				//cout<<"Correcto: "<<c<<endl;
				--letras;
			}

			if (contador==7) break;
			else if (!letras) break;
		}
		printf("Round %d\n",n );
		if (contador==7) printf("You lose.\n");
		else if (!letras) printf("You win.\n");
		else printf("You chickened out.\n");
	}
	return 0;
}