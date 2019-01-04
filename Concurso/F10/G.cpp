#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back()
typedef long long ll;
typedef pair<ll, ll> ii;


typedef vector <ll > vi;

ii f[100000];

int main()
{
	int a, c, m, x, n, q, cant, k;
	/*scanf ("%d %d %d %d %d %d", &a, &c, &m, &x, &n, &q);
	f[1]=x%m;
	for (int i = 2; i <= n; ++i)
	{
		f[i] = a* f[i-1]+ c;
		f[i] %= m;
	}
	for (int i = 1; i <= n; ++i)
		cout<<f[i]<<"\n";
	*/
	int i;
	while (scanf ("%d %d %d %d %d %d", &a, &c, &m, &x, &q, &n)!=EOF)
	{
		f[1].first=x%m;
		//f[1].second=1;
		int paps=min(n,m);
		for ( i = 2; i <= paps; ++i)
		{
			f[i].first = a* f[i-1].first+ c;
			f[i].first %= m;
			if ( f[i].first==f[1].first) break;
		}

		for(int j=1; j<=paps%(i-1); j++)
		{
			//printf("%lld\n", f[j].first);
			f[j].second = 1;
		}

		
		sort (f+1, f+i);

		cant = i -1;
		while (q--)
		{
			scanf("%d", &k);
			
			for(int j=1; j<=paps; j++)
			{
				if(k <= f[j].second+(paps/cant))
				{
					printf("%d\n", f[j].first);
					break;
				}
				k -= f[j].second+(paps/cant);
			}
		}
	}
}