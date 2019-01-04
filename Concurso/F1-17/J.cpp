#include <bits/stdc++.h>
//#define f first
//#define s second
#define m first
#define f second.first
#define w second.second
#define mk make_pair
#define pb push_back
#define tam 300005
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef pair< ll , pll > datos;
int n;
//ll m[tam], w[tam],f[tam];
//pll min_ind[tam];

ll tabla[tam];

//struct datos
//{
//	ll m, w, f;
//} mfw[tam];
datos mfw[tam];
ll copia[tam];

bool z(datos a, datos b)
{
	return a.m < b.m;
}

ll g(int i)
{
	if ( i>=n ) return 0LL;

	ll &r = tabla[i];
	if (r!=-1) return r;

	//ll tiempo = mfw[i].m;
	int t = lower_bound( copia+i, copia+n, copia[i] + mfw[i].w ) - copia;

	return r = max( g(i+1), mfw[i].f + g(t) );
}

int main()
{
	memset(tabla, -1, sizeof tabla);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		//scanf("%lld %lld %lld", &m[i], &f[i], &w[i]);
		scanf("%lld %lld %lld", &mfw[i].m, &mfw[i].f, &mfw[i].w);
		//min_ind[i] = mk(m[i], (ll)i );		
	}
	//sort(min_ind, min_ind +1); ///lower bound
	//sort(m, m+n);
	sort(mfw,mfw+n,z);
	for (int i = 0; i < n; ++i)
		copia[i] = mfw[i].m;

	ll res = g(0);
	printf("%lld\n", res);
	return 0;
}