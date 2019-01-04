#include <bits/stdc++.h>
using namespace std;
//look at my code my code is amazing
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define FOREACH(it, a) for (typeof(a.begin()) it = (a).begin(); it != (a).end(); it++)
#define ROF(i, a, b) for (int i = int(a); i >= int(b); i--)
#define REP(i, a) for (int i = 0; i < int(a); i++)
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define ALL(x) x.begin(), x.end()
#define MP(a, b) make_pair((a), (b))
#define X first
#define Y second
#define EPS 1e-9
#define DEBUG(x)   cerr << #x << ": " << x << " "
#define DEBUGLN(x) cerr << #x << ": " << x << " \n"
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<bool> vb;
//ios_base::sync_with_stdio(0);//fast entrada/salida ;-)
//cin.tie(NULL); cout.tie(NULL);

const int MAXN =  (int)(1e5)+10; // size of the biggest string

const ll mod1 = (ll) INF + 7, mod2 = (ll) INF + 9; // big primes which P*p < 2**64
ll p1[MAXN], p2[MAXN];
ll radix1 = 271, radix2 = 277; //small primes > size of alfabet

ll gcd(ll a, ll b, ll &x, ll &y)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll r = gcd(b, a%b, y, x);
	y -= a/b*x;
	return r;
}


inline ll restmod(const ll &a, const ll &b, const ll &m)
{
	return ( ( (a % m) - (b % m) ) + m ) % m;
}

inline ll divmod(const ll &a, const ll &b, const ll &m)
{
	ll binv;
	ll y;
	gcd(b, m, binv, y);

	binv = ((binv%m)+m)%m;

	return ( (a % m) * (binv % m) ) % m;
}


void preprocess()
{
	p1[0] = 1;
	p2[0] = 1;

	FOR(i, 1, MAXN)
	{
		p1[i] = p1[i-1];
		p1[i] = (p1[i] * radix1) % mod1;

		p2[i] = p2[i-1];
		p2[i] = (p2[i] * radix2) % mod2;
	}
}

string S, T;
int k;

set<pair<ll, ll>> subs;

void solve()
{
	subs.clear();
	pair<ll, ll> hash = MP(0, 0);
	REP(i, k)
	{
		hash.X = ( hash.X  + (S[i] * p1[i]) % mod1 ) % mod1;
		hash.Y = ( hash.Y  + (S[i] * p2[i]) % mod2 ) % mod2;
	}

	subs.insert(hash);

	FOR(i, k, S.size())
	{
		hash.X = restmod(hash.X, S[i-k], mod1);
		hash.Y = restmod(hash.Y, S[i-k], mod2);

		hash.X = divmod(hash.X, radix1, mod1);
		hash.Y = divmod(hash.Y, radix2, mod2);

		hash.X = ( hash.X  + (S[i] * p1[k-1]) % mod1 ) % mod1;
		hash.Y = ( hash.Y  + (S[i] * p2[k-1]) % mod2 ) % mod2;

		subs.insert(hash);
	}

	hash = MP(0, 0);
	REP(i, k)
	{
		hash.X = ( hash.X  + (T[i] * p1[i]) % mod1 ) % mod1;
		hash.Y = ( hash.Y  + (T[i] * p2[i]) % mod2 ) % mod2;
	}

	bool res = (subs.find(hash) != subs.end());
	
	FOR(i, k, T.size())
	{
		if(res)
			break;

		hash.X = restmod(hash.X, T[i-k], mod1);
		hash.Y = restmod(hash.Y, T[i-k], mod2);

		hash.X = divmod(hash.X, radix1, mod1);
		hash.Y = divmod(hash.Y, radix2, mod2);

		hash.X = ( hash.X  + (T[i] * p1[k-1]) % mod1 ) % mod1;
		hash.Y = ( hash.Y  + (T[i] * p2[k-1]) % mod2 ) % mod2;

		res = (subs.find(hash) != subs.end());		
	}

	cout << (res?"yes":"no") << '\n';

}

int main()
{
	ios_base::sync_with_stdio(0);//fast entrada/salida ;-)
	cin.tie(NULL); cout.tie(NULL);

	preprocess();

	while(cin >> S >> T >> k)
		solve();

	return 0;
}