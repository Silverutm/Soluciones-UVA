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
ll matriz[5][100000001], res;
int x[5];
vi indices, sig;
int main()
{
	int i, j, l, e;
	while (cin>>l>>x[1]>>x[2]>>x[3]>>x[4], l)
	{
		indices.clear(); indices.pb(0);
		memset(matriz, 0, sizeof matriz);
		matriz[0][0]=1;
		for (i=1; i<=4; ++i)
		{
			for (j=0; j<x[i]; ++j)
			{
				cin>>e;
				for (auto &k:indices )
				{
					if (k+e>l) continue;
					if (matriz[i][k+e]==0) sig.pb(k+e);
					matriz[i][k+e] += matriz[i-1][k];
				}
			}
			indices=sig; sig.clear();
		}
		res=0;
		for (auto&k:indices)
			res+=matriz[i][k];
		cout<<res<<endl;
	}
	return 0;
}