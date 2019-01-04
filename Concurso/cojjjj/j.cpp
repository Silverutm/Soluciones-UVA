#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef vector <int> vi;
typedef long long ll;
typedef pair <int , int> ii;

int arreglo[10004], n;
int encuentra1()
{	
	for (int i = 0; i < n; ++i)
		if (arreglo[i]==1)
			return i;
	return 0;
}

int ant(int i)
{ return (i-1+n); }
int sig(int i)
{ return (i+1); }
int f(int i)
{
	if (i>=n)
		return n-i;
	else if (i<0) return n-i;
}
int main()
{
	int i, t, cambios;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for ( i = 0; i < n; ++i)
			scanf("%d", &arreglo[i]);
		i=encuentra1();
		int cosa =2;
		cambios=0;
		while (arreglo[i]!=n)
		{
			cosa = arreglo[i]+1;
			if (arreglo[f((i+1))]==cosa)
			{
				i =f((i+1));
			}
			else if (arreglo[f((i+1))]==cosa+1)
			{
				if (arreglo[f((i-1+n))] == cosa )
				{
					swap(arreglo[i],arreglo[f((i-1+n))] );
					i = f((i-1+n));
					cambios +=2;
				}
				else if (arreglo[(i+2)] == cosa )
				{
					i =f((i+1));
					swap(arreglo[i],arreglo[f((i+1))] )	;				
					cambios +=2;
				} 

			}
			else if ( ( arreglo[f((i+1))] ) == cosa-2)
			{
				swap(arreglo[i],arreglo[f((i+1+n))] );
				i = f((i+1+n));
				cambios +=2;				
			}
		}
		printf("%d\n",cambios );
	}
	return 0;
}