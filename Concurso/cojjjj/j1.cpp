#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef vector <int> vi;
typedef long long ll;
typedef pair <int , int> ii;

int arreglo[1004], n;
int encuentra1()
{	
	for (int i = 0; i < n; ++i)
		if (arreglo[i]==1)
			return i;
	return 0;
}


int ant(int p)
{
	if (p==0) return n;
	return p;
}
int sig(int p)
{
	if (p==n+1)
		return 1;
	return p;
}
int f(int i)
{
	if (i<0 )
		return n-i;
	return i;
}
int main()
{
	int i, t, cambios, cosa, z;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for ( i = 0; i < n; ++i)
			scanf("%d", &arreglo[i]);
		//i=encuentra1();
		
		cambios=0;
		cosa =arreglo[0];
		int supuesto=0;
		for ( i = 1; i < n; )
		{
			if ( arreglo[i]==ant(cosa-1) )
			{
				swap(arreglo[supuesto], arreglo[i]);
				++i;
				++cambios;
			}
			else if ( arreglo[i] == (z=sig(cosa+1) ) )
			{
				cosa=z;
				++i;
			}
			else if (arreglo[f((i-2+n)%n)] == (z=sig(cosa+1) ) )
			{
				++cambios;
				swap(arreglo[supuesto], arreglo[f((i-2+n)%n)]);
				cosa=arreglo[i];
				++i;
			}
			else 
			{
				cosa =arreglo[i];
				swap(arreglo[i+1], arreglo[i]);
				i+=2;
				++cambios;
			}
		}
		printf("%d\n",(cambios<<1) );
	}
	return 0;
}