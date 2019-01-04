#include <bits/stdc++.h>
#define f first
#define s second
#define tam 1003
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair <int, int > ii;
typedef vector <int> vi;

int n, k;
vector <ll> xp, xn, mp, mn;
vector<ii> arr, neg;
map<int,ll> mapa[tam];

ll resolver(int c, int i)
{
	//cout<<c<<" "<<i<<endl;
	auto &ans = mapa[i][c];
	if (ans) return ans;
	int tmp;
	ll res = 0, dis=0;
	if ( c>=mp[i] )
	{
		res = c - mp[i];	//las cartas que me sobran
		if (i+1==xp.size()) return xp[i];
		if (res == 0)
			return ans = xp[i] + xp[i+1] + resolver(k, i+1);
		return ans = min( xp[i+1] - xp[i]	+ resolver(res, i+1), //avanzo con lo que me quedo
					 xp[i] + xp[i+1] + resolver(k, i+1) );//me regreso y recargo
	}
	else
	{
		tmp =  mp[i] - c;		//las cartas que me falta entregar en i
		dis += tmp / k * 2 * xp[i];	
		tmp -= tmp / k * k;		//las cartas que me falta entregar en i
								//despues de dar vueltas en i
		//if (tmp==0)///////////
		dis += 2 * xp[i];		//lleno ese residuo
		res = k - tmp;			//las que me quedaron
		if (i+1==xp.size())
		{
			if (tmp ==0 ) dis -= 2 * xp[i];
			return ans = dis + xp[i];
		}
		if (res == 0)
		{			
			return ans = dis + xp[i] + xp[i+1] + resolver(k, i+1);//me regreso y recargo
		}
		else if (res == k)
		{
			return ans = dis + xp[i+1] - xp[i] + resolver(res, i+1); //avanzo con lo que me quedo	
		}
		return ans = dis + min( xp[i+1] - xp[i]	+ resolver(res, i+1), //avanzo con lo que me quedo
					 xp[i] + xp[i+1] + resolver(k, i+1) );//me regreso y recargo
	}
}

int main()
{
	int i, x, m;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; ++i)
	{
		scanf("%d %d", &x, &m);
		arr.pb(ii{x,m});
	}

	sort(arr.begin(), arr.end());

	for (i = 0; i < n; ++i)
	{
		x = arr[i].f; m = arr[i].s;
		if (x<0)
		{
			//xn.pb(-x);
			//mn.pb(m);
			neg.pb(ii{-x, m});
		}
		else if (x)
		{
			xp.pb(x);
			mp.pb(m);
		}		
	}

	sort(neg.begin(),neg.end());
	for (auto par:neg)
	{
		x = par.f; m = par.s;
		xn.pb(x);
		mn.pb(m);
	}
	//return 0;

	ll t=0;
	if (xp.size())
		t = xp[0] + resolver(k,0);
	//return 0;
	for (i = 0; i <= xp.size(); ++i)	
		mapa[i].clear();
	xp = xn; mp = mn;
	if (xp.size())
		t += xp[0] + resolver(k,0);

	//cout<<xp[0]<<endl;
	//for (auto e: xp)
		//cout<<e<<" ";

	printf("%lld\n", t);
	return 0;
}