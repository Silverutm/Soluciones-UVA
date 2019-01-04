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
#define k first
#define d second
#define mk make_pair
using namespace std;
typedef unsigned long long ll;
typedef pair < ll, ll > ii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef vector < vi > vvi;


bool menor(ii a, ii b)
{
	if (a.k*b.d < b.k*a.d )
		return true;
	return false;
}

bool igual(ii a, ii b)
{
	if ( a.k*b.d == b.k*a.d )
		return true;
	return false;
}

string nombre[7];

int main()
{
	int i, t;
	cin>>t;
	ii g[7], u3, u2, inf, me;
	u3=ii{1,3}; u2=ii{1,2}, inf=ii{10000000000ll,1};
	while (t--)
	{
		for (i=0; i<5; ++i)
		{
			cin>>nombre[i]>>g[i].k>>g[i].d;
			if (g[i].d==0) g[i]=inf;
			if ( menor(g[i], u3) )
				cout<<nombre[i]<<" plz uninstall\n";
		}
		for (i=0; i<5; ++i)
		{
			cin>>nombre[i]>>g[i].k>>g[i].d;
			if (g[i].d==0) g[i]=inf;
		}
		me=g[0];
		for (i=0; i<5; ++i)
			if ( menor( g[i],me) ) me=g[i];
		for (i=0; i<5; ++i)
			if ( igual(me, g[i]) or menor(g[i], u2) )
				cout<<nombre[i]<<" plz uninstall\n";
	}
	return 0;
}