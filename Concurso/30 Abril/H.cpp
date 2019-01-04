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

#define maxN 100001
#define MOD 1000000007LL

int K;
char S[maxN], T[maxN];
set<ii> hs;

int main() {
	while (scanf("%s %s %d", S, T, &K) != EOF) {
		int len = strlen(S);
		hs.clear();
		ll hv = 0, hv2 = 0, val = 1, val2=1;
		FOR(i, 0, K) {
			if (i) val = val * 26LL % MOD, val2 = val2 * 27 % MOD;
			hv = (hv * 26LL + S[i] - 'a') % MOD;
			hv2 = (hv2 * 27LL + S[i] - 'a' + 1) % MOD;
		}
		hs.insert(ii(hv, hv2));
		FOR(i, K, len) {
			hv = ((hv - val*(S[i-K] - 'a')) % MOD + MOD) % MOD;
			hv = (hv * 26LL+S[i]-'a') % MOD;
			hv2 = ((hv2 - val2*(S[i - K] - 'a' + 1)) % MOD + MOD) % MOD;
			hv2 = (hv2 * 27LL + S[i] - 'a' + 1) % MOD;
			hs.insert(ii(hv, hv2));
		}
		bool ap = false;
		hv = 0, hv2=0;
		FOR(i, 0, K) {
			hv = (hv * 26LL + T[i] - 'a') % MOD;
			hv2 = (hv2 * 27LL + T[i] - 'a' + 1) % MOD;
		}
		if (hs.find(ii(hv, hv2)) != hs.end()) ap = true;
		FOR(i, K, len) {
			hv = ((hv - val*(T[i-K] - 'a')) % MOD + MOD) % MOD;
			hv = (hv * 26LL + T[i] - 'a') % MOD;
			hv2 = ((hv2 - val2*(T[i - K] - 'a' + 1)) % MOD + MOD) % MOD;
			hv2 = (hv2 * 27LL + T[i] - 'a' + 1) % MOD;
			if (hs.find(ii(hv, hv2)) != hs.end()) ap = true;
		}
		if (ap) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
