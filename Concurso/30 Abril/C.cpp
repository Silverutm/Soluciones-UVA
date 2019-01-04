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

#define maxN 1000001
#define MOD 1000000007

ll fact[maxN], rfact[maxN];

ll NK(int N, int K) {
	if (K > N) return 0;
	return fact[N] * rfact[K] % MOD*rfact[N - K] % MOD;
}

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
	fact[0] = 1;
	FOR(i, 1, maxN) {
		fact[i] = fact[i - 1] * i%MOD;
	}
	//for (int i=0; i<=10; ++i)
//		cout<<fact[i]<<endl;
//	return 0;

	rfact[maxN - 1] = fastPow(fact[maxN - 1], MOD - 2);
	for (int i = maxN - 2; i >= 0; i--) {
		rfact[i] = rfact[i + 1] * (i + 1) % MOD;
	}
	int N, K;
	while (cin >> N >> K) {
		cout << 2 * NK(N - 1, K) % MOD << endl;
	}
	return 0;
}
