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

int premios[1003][21][21];
int respueas[1003][21][21], fin, n,m;
int cx[]={1,-1,0,0,  0,  1,-1,1,-1}, cy[]={0,0, 1,-1, 0,  1,-1, -1,1};
int pep=5;
int resolver(int t, int x, int y)
{
	if (x<1 or y<1 or x>n or y>m) return 0;
	int &res=respueas[t][x][y];
	if (res!=-1) return res;
	if (t==fin+1) return res=0;
	
	for (int i=0; i<pep; ++i)
		res=max(res, resolver(t+1,x+cx[i], y+cy[i]) ) ;
	res+=premios[t][x][y];
	return res;
}

int main()
{
	int t,x, y, p, x1, y1, cas, v, i;
	cin>>cas;
	while (cas--)
	{
		memset(premios, 0, sizeof premios);
		memset(respueas, -1, sizeof respueas);
		fin=-1;
		cin>>n>>m>>p;
		cin>>x>>y;		
		for (i=0; i<p; ++i)
		{
			cin>>x1>>y1>>t>>v;
			fin=max(fin, t);
			premios[t][x1][y1]=v;
		}
		cout<<resolver(0,x, y)<<endl;
	}
	return 0;
}