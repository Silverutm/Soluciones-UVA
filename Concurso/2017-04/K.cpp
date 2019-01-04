#include <bits/stdc++.h>
using namespace std;
#define tam 1000007
typedef vector <int> vi;
typedef long long ll;
int n, w, k, arr[tam];
multiset <int> miset;
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int i, li, mi, ma;
	bool p;
	while (cin>>n>>w>>k and n)
	{		
		p = true; miset.clear();
		w = min(n - 1, w);
		for ( i = 0; i < n; ++i)
			cin>>arr[i];

		for ( i = 1; i <= w; ++i)
			miset.insert(arr[i]);

		li = n - 1;
		for ( i = 0; i < li and p; ++i)
		{
			mi = *miset.begin();
			if (!(mi>=arr[i] - k and mi<= arr[i] + k))
				p = false;

			auto it = miset.end(); --it; ma = *it;
			if (!(mi>=arr[i] - k and ma<= arr[i] + k))
				p = false;

			miset.erase(arr[i+1]); 
			if (i+w+1<n)
			miset.insert(arr[i+w +1]);
		}
		if (p) cout<<"Yes.\n";
		else cout<<"No.\n";
	}
	return 0;
}