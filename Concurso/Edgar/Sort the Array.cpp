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
#define dec 0
#define cre 1
int main()
{
	int n, ant=-1, a[100005], i, estado=cre, ini=-1, fin;
	bool estuveantes=false, posible=true;
	cin>>n;
	a[0]=-1;
	a[n+1]=1000000009;
	for (i = 1; i <= n; ++i)
	{
		cin>>a[i];
		if (estado==cre)
		{
			if (a[i-1] < a[i]) continue;
			else if (estuveantes) posible=false;
			else 
			{
				estuveantes=true;
				estado=dec;
				ini=i-1;
				fin=i;
			}
		}
		else if (estado==dec)
		{
			if ( a[i-1] > a[i] ) fin=i;
			else estado=cre;
		}

	}
	if ( ini!=-1 )
	{
		if (not( a[ini-1]<a[fin] and a[ini]<a[fin+1] ))
			posible=false;
	}
	if (posible)
	{
		printf("yes\n");
		if (ini==-1 ) printf("1 1\n");
		else printf("%d %d\n",ini, fin );
	}
	else printf("no\n");
	return 0;
}