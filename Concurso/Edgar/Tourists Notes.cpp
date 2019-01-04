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

int main()
{
	int n, m, da, ha, ds, hs, hm, ht;
	bool posible = true;
	cin>>n>>m;
	cin>>da>>ha;
	--m;
	hm = ha + da -1;
	while (m--)
	{
		cin>>ds>>hs;
		if ( abs(ds-da)<abs(hs-ha) )
		{
			posible = false;
			break;
		}
		ht =max(hs, ha) + ( abs(ds-da) - abs(hs-ha) )/2;
		hm = max(hm, ht);

		da=ds; ha=hs;
	}
	hm = max(hm, ha + n - da);
	if (posible) cout<<hm<<endl;
	else cout<<"IMPOSSIBLE\n";
	return 0;
}