#include <bits/stdc++.h>
#define f first
#define s second
#define tam 200005
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll n, a[tam], b[tam], res[tam], maxi[tam], w[tam];
ii a_b[tam];
int k;

bool fu(ii u, ii v)
{	return u.s < v.s; }

int main()
{	
	int i, j;
	scanf("%lld %d", &n, &k);
	for (i = 1; i <= k; ++i)
		scanf("%lld %lld", &a_b[i].f, &a_b[i].s);

	sort(a_b + 1, a_b + k + 1, fu);
	for (i = 1; i <= k; ++i)
	{
		a[i] = a_b[i].f;
		b[i] = a_b[i].s;
		w[i] = b[i] - a[i] + 1;
	}

	for (i = 1; i <= k; ++i)
	{
		j = (lower_bound(b, b + i, a[i]) - b) - 1;
		res[i] = w[i] + maxi[j];
		maxi[i] = max(maxi[i-1], res[i]);
	}
	printf("%lld\n", n - maxi[k]);
	return 0;
}