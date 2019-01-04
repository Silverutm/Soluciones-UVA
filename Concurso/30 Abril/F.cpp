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
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define maxN 1000001
#define MOD 987654321
#define PHI 619703040

bool np[maxN];
vi primes;

ll fastPow(ll x, ll n) {
	ll ret = 1;
	while (n) {
		if (n & 1) ret = ret*x%MOD;
		x = x*x%MOD;
		n >>= 1;
	}
	return ret;
}

int main() {
	FOR(i, 2, maxN / 2) if (!np[i]) {
		for (int j = 2; i*j < maxN; j++) {
			np[i*j] = true;
		}
	}
	FOR(i, 2, maxN) if (!np[i]) primes.push_back(i);
	int N, K;
	while (scanf("%d %d", &N, &K)!=EOF) {
		ll a1 = 1, a2 = 1;
		FOR(i, 0, primes.size()) 
		{
			int c = 1;
			ll t = primes[i];
			while (t <= N) 
			{
				c += N / t;
				t *= primes[i];
			}
			a1 = a1*c%MOD;
			
			c = 1;
			t = primes[i];
			while (t <= K)
			 {
				c += K / t;
				t *= primes[i];
			}
			a2 = a2*c%MOD;
		}
		printf("%d\n", (a1 - a2+1 + MOD) % MOD);
	}
	return 0;
}
