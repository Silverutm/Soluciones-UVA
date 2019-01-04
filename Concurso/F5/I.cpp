#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>
#define pb push_back
#define mk make_pair
#define f first
#define s second
using namespace std;
typedef pair <int, int> ii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef long long ll;
double porcentaje[510];
double total, votos, sumvotos[510];
int C;
int maximo()
{
	int i, j;
	i=1;
	for (j=1;j<=C; ++j)
		if (sumvotos[j]>sumvotos[i])
			i=j;
	return i;
}

int main()
{
	int t, i, j, E;
	cin>>t;
	while (t--)
	{
		scanf("%d %d", &C, &E);
		memset(sumvotos, 0, sizeof sumvotos);
		total=0;
		for (i=1; i<=E; ++i)
		{
			for (j=1;j<=C; ++j)
				scanf("%lf", &porcentaje[j]);
			scanf("%lld", &votos);
			//cout<<"votos  "<<votos<<endl;
			total+=votos;
			for (j=1;j<=C; ++j)
				sumvotos[j]+=porcentaje[j]*votos+.5;
		}
		for (j=1;j<=C; ++j)
			porcentaje[j]=(double)sumvotos[j]/total;
		for (j=1;j<=C; ++j)
			if (porcentaje[j]>=50.1)
			{
				printf("%d %lld\n", j,sumvotos[j]/100);
				break;
			}
		//cout<<"j  "<<j<<endl;
		if (j>C)
		{
			i=maximo();
			printf("%d %lld\n", i,sumvotos[i]/100);
			sumvotos[i]=-1;
			i=maximo();
			printf("%d %lld\n", i,sumvotos[i]/100);
		}
		if (t) cout<<endl;
	}
	return 0;
}