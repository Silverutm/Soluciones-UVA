#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
int n,m;
ll barrras[20], discos[20];
set<ll> res, otro;
map <ii, bool> mapa[20];

void f(ii par, int ni)
{	
	ll izq=par.f, der=par.s;
	if (izq==der) res.insert(par.f);
	//cout<<izq<<"  "<<der<<endl;

	if (ni == m) return ;
	if ( mapa[ni][par] ) return;
	mapa[ni][par] = true;

	f(  ii{ max(izq+discos[ni], der), min(izq+discos[ni], der)} , ni+1);
	f(  ii{ max(izq, der+discos[ni]), min(izq, der+discos[ni])} , ni+1);
	f(  par , ni+1);
	
}

int main()
{	
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &barrras[i]);

	for (int i = 0; i < m; ++i)
		scanf("%lld", &discos[i]);

	f(ii{0,0},0);
	for (int i = 0; i < n; ++i)
		for (auto &e:res)
			otro.insert((e<<1) + barrras[i]);

	for (auto &e:otro)
		printf("%lld\n",e );
	return 0;
}