#include <iostream>
#include <set>
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair < ll, ll > pll;

ll p1=29, p2=31, mod=1000000007;
pll dp[30][100008], renglon[100008];

set < pll > tablahash;
string s, t;
int k; 
void pre()
{
	int i, j;
	renglon[0].f=renglon[0].s=1;
	for (i=1; i<=100004; ++i)
	{
		renglon[i].f = renglon[i-1].f * p1 % mod;
		renglon[i].s = renglon[i-1].s * p2 % mod;
	}

	for (i=0; i<=27; ++i)
		for (j=0; j<=100004; ++j)
		{
			dp[i][j].f = renglon[j].f * i % mod;
			dp[i][j].s = renglon[j].s * i % mod;
		}
	return ;

}

int main()
{
	pre();
	int i, j;
	bool posible;
	pll mihash;
	while (cin>>s>>t>>k)
	{
		mihash.f=mihash.s=0;
		tablahash.clear();
		//hacer la primera
		for (i=0; i<k; ++i)
		{
			mihash.f = (mihash.f + dp[ s[i]-'a' ][ k-1-i ].f) %mod;
			mihash.s = (mihash.s + dp[ s[i]-'a' ][ k-1-i ].s) %mod;
		}
		tablahash.insert( mihash );
		//cout <<mihash.f<<" "<<mihash.s<< endl;
		for ( j=0 ; i<s.size(); ++i, ++j)
		{
			mihash.f = ( mihash.f - dp[ s[j]-'a' ][ k-1 ].f + mod ) % mod;
			mihash.f = mihash.f * p1 % mod;
			mihash.f = ( mihash.f + dp[ s[i]-'a' ][ 0 ].f ) % mod;

			mihash.s = ( mihash.s - dp[ s[j]-'a' ][ k-1 ].s + mod ) % mod;
			mihash.s = mihash.s * p2 % mod;
			mihash.s = ( mihash.s + dp[ s[i]-'a' ][ 0 ].s ) % mod;
			//cout <<mihash.f<<" "<<mihash.s<< endl;
			tablahash.insert(mihash );
		}

		//cout<<"\n";
		mihash.f=mihash.s=0;
		for (i=0; i<k; ++i)
		{
			mihash.f = (mihash.f + dp[ t[i]-'a' ][ k-1-i ].f) %mod;
			mihash.s = (mihash.s + dp[ t[i]-'a' ][ k-1-i ].s) %mod;
		}
		//cout <<mihash.f<<" "<<mihash.s<< endl;
		posible=false;
		if ( tablahash.find( mihash )!=tablahash.end() ) posible=true;

		for ( j=0 ; i<s.size(); ++i, ++j)
		{
			mihash.f = ( mihash.f - dp[ t[j]-'a' ][ k-1 ].f + mod ) % mod;
			mihash.f = mihash.f * p1 % mod;
			mihash.f = ( mihash.f + dp[ t[i]-'a' ][ 0 ].f ) % mod;

			mihash.s = ( mihash.s - dp[ t[j]-'a' ][ k-1 ].s + mod ) % mod;
			mihash.s = mihash.s * p2 % mod;
			mihash.s = ( mihash.s + dp[ t[i]-'a' ][ 0 ].s ) % mod;

			//cout <<mihash.f<<" "<<mihash.s<< endl;
			if ( tablahash.find( mihash )!=tablahash.end() ) posible=true;
		}



		if (posible) cout<<"yes\n";
		else cout<<"no\n";


	}
	return 0;
}
