#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define MOD 1000000007
#define maxN 100001

ll fastPow(ll x, ll n) {
	ll ret = 1;
	while (n) {
		if (n & 1) ret = ret*x%MOD;
		x = x*x%MOD;
		n >>= 1;
	}
	return ret;
}

ll num[maxN], r[maxN], l[maxN], self[maxN];

int main() {
	int N;
	while (scanf("%d", &N)!=EOF) {
		ll invN = fastPow(N, MOD - 2);
		FOR(i, 0, N) {
			self[i] = 1;
			l[i] = (-(i*invN%MOD) + MOD) % MOD;
			r[i] = (-((N - i)*invN%MOD) + MOD) % MOD;
			num[i] = 1;
		}
		r[N - 1] = 0;
		for (int i = N - 1; i; i--) {
			ll invS = fastPow(self[i], MOD - 2);
			l[i] = l[i] * invS % MOD*r[i - 1] % MOD;
			num[i] = num[i] * invS%MOD*r[i - 1] % MOD;
			self[i] = r[i - 1];
			r[i - 1] = (r[i - 1] - self[i] + MOD) % MOD;
			self[i - 1] = (self[i - 1] - l[i] + MOD) % MOD;
			num[i - 1] = (num[i - 1] - num[i] + MOD) % MOD;
		}
		ll ans = num[0] * fastPow(self[0], MOD - 2) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
