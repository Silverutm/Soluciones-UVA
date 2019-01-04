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
ll matriz[2][1000001], res;
int x[5];
vi indices, sig;
bool mover;
int i, j, l, e;
void fm()
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
	mover=false;
	indices.clear();
	//indices=sig; sig.clear();
}

void fk()
{
	for (j=0; j<x[i]; ++j)
	{
		scanf("%d", &e);
		//cout<<e<<" ";
		for (auto &k:sig )
		{
			if (k+e>l) continue;
			if (matriz[1][k+e]==0) indices.pb(k+e);
			matriz[1][k+e] += matriz[0][k];
		}
	}
	//cout<<endl;
	for (auto &k:sig)
		matriz[0][k]=0;
	if (i<4)
	for (auto&k: indices)
	{
		matriz[0][k]=matriz[1][k];
		matriz[1][k]=0;
	}
	mover=true;
	sig.clear();
	//indices=sig; sig.clear();
}
int main()
{
	while (scanf("%d %d %d %d %d", &l, &x[1], &x[2], &x[3], &x[4]) and l)
	{
		mover=true;
		for (auto &k:indices)
				matriz[1][k]=0;
		indices.clear(); indices.pb(0); sig.clear();
		//memset(matriz, 0, sizeof matriz);
		matriz[0][0]=1;
		for (i=1; i<=4; ++i)
		{
			if (mover)
			{
				fm();
			}
			else
			{
				fk();
			}
		}
		res=0;
		for (auto&k:indices)
			res+=matriz[1][k];
		printf("%lld\n",res );
	}
	return 0;
}