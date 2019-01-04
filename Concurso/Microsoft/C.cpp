#include <bits/stdc++.h>
using namespace std;
int arreglo[400];
long long factorial(long long n)
{
	if (n<2) return 1;
	else return n*factorial(n-1);
}

int main()
{
	string s;
	long long impar, i, j, respuesta, suma;
	while (cin>>s)
	{
		memset(arreglo, 0 , sizeof arreglo);
		impar=0;
		for (auto c:s)
			arreglo[c]++;
		for (i='a'; i<='z'; ++i)
			if ( (arreglo[i])%2 ==1 ) ++impar;
		impar;
		i='a'-1;
		for (j=0; j<impar;)
			if ( (arreglo[++i])%2 ==1 )
				{
					--arreglo[i];
					++j;
				}
		suma=0;
		for (i='a'; i<='z';++i)
			suma+=arreglo[i];
		suma /=2;
		respuesta=factorial(suma);
		for (i='a'; i<='z';++i)
			respuesta /=factorial(arreglo[i]/2);
		if (impar>0) --impar;

		printf("%lld,%lld\n", impar, respuesta);
	}
	return 0;
}