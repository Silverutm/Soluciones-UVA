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
#define tam 305
int matriz[tam][tam], rescols[tam], resvec[tam][tam];
int r, c;

int solvector(int col, int renglon)
{
	if (col >= c or renglon>=r) return 0;
	int &res= resvec[renglon][col];
	if (res!=-1) return res;
	res=max( matriz[renglon][col] + solvector(col, renglon+2),
			 matriz[renglon+1][col] + solvector(col, renglon+3) );
	return res;
}

int solmatriz(int col)
{
	if (col>=c) return 0;
	int &res=rescols[col];
	if (res!=-1) return res;
	res=max( solvector(col, 0) + solmatriz(col+2),
			 solvector(col+1,0) + solmatriz(col+3) );
	return res;
}

int main()
{
	int i, j;
	while ( scanf("%d %d", &r, &c)==2 )
	{
		for (i=0; i<r; ++i)
			for (j=0; j<c; ++j)
				scanf("%d", &matriz[i][j]);
		for (j=0; j<c; ++j)
			matriz[i][j]=0;
		memset( rescols, -1, sizeof rescols);
		memset( resvec, -1, sizeof resvec);
		printf("%d\n", solmatriz(0) );
	}
	return 0;
}