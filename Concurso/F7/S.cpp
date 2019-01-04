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

bool tiene3(int n)
{
	string s=to_string(n);
	for (auto &c:s)
		if (c=='3')
			return true;
	return false;
}
int nen2(int n)
{
	return n*(n-1)/2;
}
int main()
{
	int n, l, res, p;
	while (cin>>n>>l)
	{
		
		res=nen2(n-3*l+2);
		//p=n-3*l;
		for (int i=1; i<=n-3*l; ++i)
			if ( tiene3(l+i) )
			{
				res-=3;
				//if ((n-3*l-i)==0)
				//	res-=3;
				//else
				//res-=(n-3*l-i)*2*3;
			}
		//for (int i=1; i<=l+p; ++i)
		//	if (tiene3(i)) res-=3;
		cout<<res%12345647<<endl;
	}
	
	return 0;
}
//[m en k]*9^(m-k)
//N-3L+2  en 2