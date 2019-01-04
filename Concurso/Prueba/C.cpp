#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair <int, int> ii;
typedef vector < ii > vii;
#define tam 1009
#define INF 100000000
int p[tam], n, l,b;
double t[tam], sol[tam];

double solucion(int i)
{
	double tiempo=0;
	int j;
	if (i==n) return 0;
	double &res=sol[i];
	if (res!=INF) return res;
	int peso=0;
	j=i;
	tiempo=max(tiempo, t[j]);
	peso+=p[j];	
	while ( peso<=b  )
	{
		res=min(res, solucion(j+1) +tiempo );
		++j;
		if (j==n) break;
		tiempo=max(tiempo, t[j]);
		peso+=p[j];	
	}
	return res;

}

int main()
{
	double res;
	int i;
	while ( scanf("%d %d %d",&b, &l,&n)==3, b )
	{
		for (i=0; i<n; ++i)
			scanf("%d %lf",&p[i],&t[i]);
		for (i=0; i<n; ++i)
		{
			t[i] = l/t[i];
			sol[i]=INF;
		}
		res=solucion(0);
		printf("%.1lf\n", res*60);
	}
	return 0;
}