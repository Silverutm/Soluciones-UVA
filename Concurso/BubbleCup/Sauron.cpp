#include <bits/stdc++.h>
#define f first
#define s second
#define mk make_pair
#define pb push_back
#define tam 5001
using namespace std;
typedef unsigned long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;
int arr[50];
int main()
{
	int t = 15;
	bool nel;
	ll cuenta;
	for (int n = 2; n <= t; ++n)
	{
		for (int k = 1; k <= n; ++k)
			arr[k] = k;
		cuenta = 0;
		while ( next_permutation(arr + 1, arr + n + 1) )
		{
			nel = false;
			for (int k = 1; k < n and not nel; ++k)
				if (arr[k]+1==arr[k+1])
					nel = true;

			if (not nel) ++cuenta;
		}
		cout<<n<<" "<<cuenta<<endl;
	}
}