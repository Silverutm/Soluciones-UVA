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
vi v;
int main()
{
	int n, a;
	bool sumar, posible = true;
	cin>>n;
	while ( n-- )
	{
		cin>>a;
		v.pb( a );
	} n= v.size();
	while ( v[0] )
	{
		sumar = true;
		for (auto & e: v)
		{
			if ( sumar )
				e = ( e + 1 )%n;
			else e = ( e - 1 + n) % n;
			sumar = not sumar;
		}
	}
	for (int i = 0; i < n; ++i)
		if ( v[i]!=i ) posible = false;
	if (posible) printf("YES\n");
	else printf("NO\n");
	return 0;
}