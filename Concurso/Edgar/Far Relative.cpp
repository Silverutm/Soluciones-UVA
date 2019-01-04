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
int n;
int m[500], f[500], r, li;
int main()
{
	char c;
	int a, b;
	cin>>n;
	for (int i = 0; i < n ; ++i)
	{
		cin>>c>>a>>b;
		li=max(li,b);
		if (c=='F')
			for (int j = a; j <= b; ++j)
				++f[j];
		else for (int j = a; j <= b; ++j)
				++m[j];
		//cout<<c<<endl;
	}
	for (int i = 1; i <= li; ++i)
	{
		m[i] = min(m[i], f[i]);
		r= max(r, m[i]);
	}
	cout<<2*r<<endl;
	return 0;
}