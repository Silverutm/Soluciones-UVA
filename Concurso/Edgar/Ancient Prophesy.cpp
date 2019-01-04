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
int mes[] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};
string s, sr;
int i;
bool c(char a)
{ return a!='-';}
int r(char c, int t )
{
	c -= '0';
	int p=1;
	for ( int j = 0; j < t; ++j )
		p *= 10;
	return p*c;
}
bool g(int a, int b, int c)
{
	return a>=b and a<= c;
}
map <string, int> mapa;
int main()
{	
	cin>>s;
	for ( i = 0; i < s.size() - 5; ++i )
		if (c(s[i]) and c(s[i+1]) and !c(s[i+2]) 
			and c(s[i+3]) and c(s[i+4]) and !c(s[i+5]) and
			c(s[i+6]) and c(s[i+7]) and c(s[i+8]) and c(s[i+9]) )
			if ( g(r(s[i+6], 3) + r(s[i+7], 2) + r(s[i+8], 1) +r(s[i+9], 0), 2013, 2015) )
				if ( g(r(s[i+3],1)+ r(s[i+4],0), 1, 12) )
					if ( g( r(s[i],1) + r(s[i+1],0), 1, mes[ r(s[i+3],1)+ r(s[i+4],0) ]) )
						mapa[s.substr(i, 10)]++;
	int t=0;
	for ( auto e: mapa )
		if ( e.s > t )
		{
			sr = e.f;
			t = e.s;
		}
	cout<<sr<<endl;
	return 0;
}