#include <cstdio>
//using namespce std;

int GCD(int a, int b)
{
	return b ==0 ? a:GCD(b, a%b);
}

int main()
{
	int respuesta, i, j, n;
	while (scanf("%d", &n), n)
	{
		respuesta=0;
		for(i=1;i<n;i++)
			for(j=i+1;j<=n;j++)
			respuesta += GCD(i,j);
		printf("%d\n",respuesta );
	}
	return 0;
}