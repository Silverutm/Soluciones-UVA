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
ll n, x, y, xi=1000000009, xs=-1000000009, yi=1000000009, ys=-1000000009,xp,yp;
int main()
{
	cin>>n;
	while (n--)
	{
		cin>>x>>y;
		xi=min(xi, x); xs=max(xs, x);
		yi=min(yi, y); ys=max(ys, y);
	}
	xp=xs-xi; yp=ys-yi; xp=max(xp,yp);
	cout<<xp*xp<<endl;
	return 0;
}