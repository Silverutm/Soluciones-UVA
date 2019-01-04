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
vi ig, dif;
int n, t, i;
string s1, s2, sr;
int main()
{
	cin>>n>>t;
	t = n - t;
	cin>>s1>>s2;

	for (int i = 0; i < n; ++i)
	{
		if ( s1[i]!='c' and s2[i]!='c' )
			sr.pb('c');
		else if ( s1[i]!='a' and s2[i]!='a' )
			sr.pb('a');
		else sr.pb('b');
		
		if ( s1[i]!=s2[i] )
			dif.pb(i);
		else ig.pb(i);
	}
	if ( t > ig.size() + dif.size()/2 )
	{
		cout<<-1<<endl;
		return 0;
	}
	i=0; 
	while ( t and i<ig.size() )
	{
		t--;
		sr[ ig[i] ] = s1[ ig[i] ];
		++i;
	}
	i=-1;
	while (t)
	{
		++i;
		sr[ dif[i] ] = s1[ dif[i] ];
		++i;
		sr[ dif[i] ] = s2[ dif[i] ];
		--t;
	}
	cout<<sr<<endl;
	return 0;
}