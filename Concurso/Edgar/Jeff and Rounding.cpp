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
double d, res;
int n, a, m, a1;
vector <double> v;
int main()
{
	cin>>n;
	m = 2*n;
	while (m--)
	{
		cin>>d;
		a = int(d);
		v.pb( d-a );
	} m = 2*n;
	sort(v.begin(), v.end());
	for (auto e:v)
		cout<<e<<" ";
	cout<<endl;
	res = 0.0;
	for (int i = 0; i < n; ++i)
	{
		res += v[ i ];
		if (v[ m - 1 - i ]!=0.0)
			res += -1 + v[ m - 1 - i ];
	}
	cout<<res<<endl;
	return 0;
}