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

map < int, ii > mapa;
pair < int, ii > res;
int main()
{
	int n, a;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		++mapa[a].f;
		mapa[a].s=i;
	}
	for (auto & e:mapa)
		if ( e.s.f > res.s.f ) res=e;
		else if ( e.s.f == res.s.f )
			if ( e.s.s < res.s.s ) res=e;
	cout<<res.f<<endl;
	return 0;
}