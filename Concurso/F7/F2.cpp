#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <bitset>
#include <map>
#include <cmath>
#include <queue>
#define f first
#define s second
#define mk make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;
ll matriz[2][100001], res;
int x[5];
vi indices, sig;
int main()
{
	int i, j, l, e;
	while (scanf("%d %d %d %d %d", &l, &x[1], &x[2], &x[3], &x[4]) and l)
	{
		for (auto &k:indices)
				matriz[1][k]=0;
		indices.clear(); indices.pb(0);
		//memset(matriz, 0, sizeof matriz);
		matriz[0][0]=1;
		for (i=1; i<=4; ++i)
		{
			for (j=0; j<x[i]; ++j)
			{
				scanf("%d", &e);
				//cout<<e<<" ";
				for (auto &k:indices )
				{
					if (k+e>l) continue;
					if (matriz[1][k+e]==0) sig.pb(k+e);
					matriz[1][k+e] += matriz[0][k];
				}
			}
			//cout<<endl;
			for (auto &k:indices)
				matriz[0][k]=0;
			if (i<4)
			for (auto&k: sig)
			{
				matriz[0][k]=matriz[1][k];
				matriz[1][k]=0;
			}
			indices=sig; sig.clear();
		}
		res=0;
		for (auto&k:indices)
			res+=matriz[1][k];
		printf("%lld\n",res );
	}
	return 0;
}