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

#define maxN 501
#define MOD 1000000007
#define maxSum 5000
#define digits 10

ll dp[maxN][maxSum];
char l[maxN], r[maxN];
bool prime[maxSum];

ll solve(int n, int s) {
	if (!n) return prime[s];
	ll &c = dp[n][s];
	if (~c) return c;
	c = 0;
	FOR(i, 0, digits) {
		c = (c + solve(n - 1, s + i)) % MOD;
	}
	return c;
}

ll getAns(char *p) {
	int len = strlen(p), ans = 0, sum = 0;
	FOR(i, 0, len) {
		FOR(j, '0', p[i]) {
			ans = (ans + solve(len - i - 1, sum + j - '0')) % MOD;
		}
		sum += p[i] - '0';
	}
	return ans;
}

int isPrime(char *p) {
	int len = strlen(p), sum=0;
	FOR(i, 0, len) {
		sum += p[i] - '0';
	}
	return prime[sum];
}

int main() {
	memset(prime, true, sizeof(prime));
	FOR(i, 2, maxSum) for (int j = 2; i*j < maxSum; j++) prime[i*j] = false;
	prime[0] = prime[1] = false;
	memset(dp, -1, sizeof(dp));
	while (scanf("%s %s", &l, &r) != EOF) {
		ll a1 = getAns(r);
		ll a2 = getAns(l);
		printf("%lld\n", (a1 - a2 + MOD + isPrime(r)) % MOD);
	}
	return 0;
}
