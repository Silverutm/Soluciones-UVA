#include <bits/stdc++.h>
#define f first
#define s second
#define mk make_pair
#define pb push_back
#define tam 505
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;
ll tabla[tam];

ll f(int n)
{
	ll & r = tabla[n];
	if (r != -1) return r;
	return r = (n*f(n-1) + (n-1)*f(n-2))%mod;
}

int main()
{
	memset(tabla, -1, sizeof tabla);
	tabla[0] = tabla[1] = 1;
	int n;
	scanf("%d", &n);
	printf("%lld\n", f(n - 1));
}