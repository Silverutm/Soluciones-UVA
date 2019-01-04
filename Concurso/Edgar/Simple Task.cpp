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

int n, q, i, j, k;
string s;
bool f(char a, char b)
{
	if ( k )
		return a < b;
	else return a > b;
}
int a[100005];

bool nopasa()
{
	for (int w=i; w<j; ++w)
		if ( a[w]!=k ) return true;
	return false;
}

int main()
{
	cin>>n>>q;
	cin>>s;
	//k=0; sort(s.begin(),s.end(), f);
	for (int w=0; w<n;++w) a[w]=-1;
	while (q--)
	{
		cin>>i>>j>>k;
		--i; j;
		if ( nopasa() )
		{
			sort(s.begin() + i , s.begin() + j, f );
			for (int w=i; w<j; ++w) a[w]=k;
		}
	}
	cout<<s<<endl;
	return 0;
}