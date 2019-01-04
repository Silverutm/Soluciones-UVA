#include <bits/stdc++.h>
#define f first
#define s second
#define tam 200005
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair <int, int > ii;
typedef vector <int> vi;

int n, q, l, r;
ll precios[tam];
map < ll,pair<bool,ll> > mapa[tam];

ll resolver(int i, ll v)
{	
	if (i==r) return v;

	v %= precios[i];
	auto &res = mapa[i][v];
	res.f = true;
	if (v == 0) return res.s = v;

	return res.s = resolver(v, i+1);
}

int main()
{
	int i;
	ll v;
	scanf("%d %d", &n, &q);
	for (i = 0; i < n; ++i)
		scanf("%lld", &precios[i]);

	for (i = 0; i < q; ++i)
	{
		scanf("%lld %d %d", &v, &l, &r);
		v = resolver(l,v);
		//for ( --l; l < r; ++l)
		//{
		//	v %= precios[l];
		//
		//}
		printf("%lld\n", v);
	}

	return 0;
}