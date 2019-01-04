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
char matriz[20][29];
int main()
{
	int a, b, i, j;
	int y=4,x=3;
	//scanf("%d %d", &a, &b);
	for (i=0; i<y; ++i)
		for (j=0; j<x; ++j)
		{
			scanf("%c", &matriz[i][j]	);

			//matriz[i][j]=getchar();
		}
	
	for (i=0; i<y; ++i)
		for (j=0; j<x; ++j )
			
			{
				printf("%d %d %d %c\n", i,j,matriz[i][j],matriz[i][j]);

			}
	//while (cin>>a>>b)
	printf("%c", matriz[2][1]);
	return 0;
}