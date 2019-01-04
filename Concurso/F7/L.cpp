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
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main()
{
	int n, t, a, b, i;
	string s, s1, s2;
	
	cin>>n;
	bool bol;
	//cout<<n<<endl;
	for (t=1; t<=n; ++t)
	{
		cin>>s;
		bol=true;
		for (i=0;i<s.size()-1 and bol; ++i )
		{
			s1=s.substr(0,i+1);
			s2=s.substr(i+1, s.size()-i-1);
			a=stoi(s1); b=stoi(s2);
			if (gcd(a,b)==1)
			{
				printf("Ticket #%d:\n%d %d\n",t, a, b );
				bol=false;
			}
		}
		if (bol) printf("Ticket #%d:\nNot relative\n",t );
	}
	return 0;
}