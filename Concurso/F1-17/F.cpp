#include <bits/stdc++.h>
#define f first
#define s second
#define mk make_pair
#define pb push_back
#define tam 105
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;

int n, k, a, s;
string cad;
int main()
{
	scanf("%d %d", &n, &k);
	s=1;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		cin>>cad;

		if (cad[0] =='S')
			s = max(s, a);
		else k = min(k, a);		
	}

	if (k-s > 1)
			printf("%d %d\n",s+1, k-1 );
		else printf("%d %d\n",k, s );
	return 0;
}