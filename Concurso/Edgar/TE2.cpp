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

vi Lista;

int main()
{
	int pasos=0, x1,x2,y1,y2, a, n;
	cin>>n;
	while (n--)
	{ cin>>a; Lista.pb(a); }
	cin>>y1>>x1>>y2>>x2;
	ii p(y1-1,x1-1), fi(y2-1, x2-1);

	if (y1 > y2) swap(p,fi);

	while (p.f < fi.f)
	{
		++pasos;
		++p.f;
		p.s = min( p.s, Lista[p.f] );
	}
	pasos += abs(p.s-fi.s);
	cout<<pasos<<endl;
	return 0;
}