#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef vector <int> vi;
typedef long long ll;
typedef pair <int , int> ii;

int arreglo[1000005];
int sumadigitos(int i)
{
	int res=0;
	while (i)
	{
		res+=i%10;
		i /=10;
	}
	return res;
}
int main()
{
	int k, n;
	memset(arreglo, -1, sizeof arreglo);
	for (int i = 11; i < 1000001; i+=11)
	{	
		k=sumadigitos(i);
		if (arreglo[k]==-1)
			arreglo[k]=i;
	}
	n=0;
	while (n<1000000)
	{
		if (arreglo[n]!=-1)
			printf("%3d: %6d\n",n, arreglo[n] );
		++n;
	}
	return 0;
}