#include <bits/stdc++.h>
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

bool volcal(char c)
{
	for ( auto i:{'a', 'e', 'i', 'o', 'u', 'y'} )
		if (i==c) return true;
	return false;
}

int main()
{
	string s;
	cin>>s;
	for (auto &c:s)
	{
		c=tolower(c);
		if ( volcal(c) ) continue;
		cout<<'.'<<c;
	}
	cout<<endl;
	return 0;
}