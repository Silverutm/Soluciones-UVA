#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <queue>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef pair <int, int> ii;
typedef vector < ii > vii;

int matriz[105][105];
int n, m;
char a;
int x[]={0,1,0,-1}, y[]={-1,0,1,0};
vii actual, siguiente;
int tam;
void imprime(int t)
{
	if (tam>=10)
	{
		if (t==0)
			cout<<"...";
		else if (t<10)
			cout<<".."<<t;
		else cout<<"."<<t;
	}
	else
	{
		if (t==0)
			cout<<"..";
		else if (t<10)
			cout<<"."<<t;
		else cout<<t;
	}
}

int main()
{
	int i, j;
	while (cin>>n>>m)
	{
		//memset(matriz, -1, sizeof matriz);
		for (i=0; i<=m+1; ++i)
		{
			matriz[0][i]=matriz[n+1][i]=0;
			actual.pb(ii{0,i});
			actual.pb(ii{n+1,i});
		}
		for (i=0; i<=n+1; ++i)
		{
			matriz[i][0]=matriz[i][m+1]=0;
			actual.pb(ii{i,0});
			actual.pb(ii{i,m+1});
		}
		for (i=1; i<=n; ++i)
			for (j=1; j<=m; ++j)
			{
				cin>>a;
				if (a=='.')
				{
					matriz[i][j]=0;
					actual.pb(ii{i,j});
				}
				else matriz[i][j]=50000;
			}
		tam=1;
		while ( actual.size() )
		{
			siguiente.clear();
			for (auto p:actual)
			{
				for(int w=0; w<4; ++w)
					if (matriz[ p.f+y[w] ][ p.s+x[w] ]==50000)
					{
						matriz[ p.f+y[w] ][ p.s+x[w] ]=tam;
						siguiente.pb( ii{p.f+y[w] , p.s+x[w]} );
					}
			}
			actual=siguiente;
			tam++;
		}

		//for (i=0; i<=n+1; ++i)
		//	for (j=0; j<=n+1; ++j)
				//if (matriz[i])
		/*for (i=1; i<=n; ++i)
			for (j=1; j<=n; ++j)
				if (matriz[i][j]==50000)
				{
					//matriz[i][j]=50000;
					for(int w=0; w<4; ++w)
					matriz[i][j]=min(matriz[i][j], matriz[i+y[w]][j+x[w]]);
					matriz[i][j]+=1;
				}*/

		for (i=1; i<=n; ++i, cout<<endl)
			for (j=1; j<=m; ++j)
				imprime(matriz[i][j]);
	}
	return 0;
}
