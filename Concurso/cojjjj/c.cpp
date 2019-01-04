#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;


typedef long long ll;
typedef vector <ll> vi;
typedef pair <int , int> ii;


int main(int argc, char const *argv[])
{

	int n, k;
	int t;
	scanf("%d", &t);
	while(t--)
	{
		cin >> n >> k;
		int contador = n - k + 1;
		vi v;
		ll ni;

		for (int i = 0; i < n; ++i)
		{
			scanf("%lld", &ni);
			v.pb(ni);
		}

		map <ll, int> items;
		int i = 0;

		for (i = 0; i < k; ++i)
			 items[v[i]]++;
		--i;
		bool primera=true;
		int j=0;
		for (; i < n;)
		{
			//printf("iteracion %d\n",i );
			auto c =  items.end();
			c--;
			if (primera)
				printf("%lld", (*c).first);
			else printf(" %lld", (*c).first);
			primera=false;
			
			auto eli = items.find(v[j]);
			(*eli).second--;
			if ((*eli).second == 0)
			{
				items.erase(eli);
			}
			++i;
			if (i<n)
			items[v[i]]++;
			++j;
		}
		printf("\n");

	}
	
	return 0;
}