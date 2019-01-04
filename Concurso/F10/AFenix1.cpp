#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define clr(a, b) memset(a, b, sizeof(a))
#define f(a, b, c) for(int a = b; a < c; a++)
typedef long double ld;
typedef long long ll;
#define N 1002
#define C 26

ll DP[C][N][N]; 
ll S[C][N][N];
int run = -1;
ld comb[N][N];
ll combm[N][N];
vector<int> rights[N];
char s[N];
int freq[C];
int n, k;
ll mod = 1000000009;

ll solve(int pos, int sum, ll falta) {
	if (pos >= C) return falta == 1;
	ll &res = DP[pos][sum][falta];
	ll &s = S[pos][sum][falta];
	if (s == run) return res;
	s = run;
	res = 0;
	f(i, 0, rights[sum].size()) {
		int c = rights[sum][i];
		int d = c - sum;
		if (d > freq[pos]) break;
		if (falta % combm[sum][c] == 0)
			res += solve(pos + 1, c, falta / combm[sum][c]) * combm[d][freq[pos]] % mod;
	}
	res %= mod;
	return res;
}

int main() {
	clr(comb, 0);
	clr(combm, 0);
	f(i, 0, N) {
		comb[0][i] = combm[0][i] = 1;
		f(j, 1, i + 1) {
			comb[j][i] = (comb[j - 1][i - 1] + comb[j][i - 1]);
			combm[j][i] = (combm[j - 1][i - 1] + combm[j][i - 1]) % mod;
		}
	}
	f(i, 0, N)
		f(j, i, N) if (comb[i][j] <= 1000) rights[i].push_back(j);

	clr(S, -1);

	while(scanf("%s", s) == 1) {
		run++;
		scanf("%d", &k);
		clr(freq, 0); 
		n = strlen(s);
		f(i, 0, n) 
			freq[s[i] - 'a']++;
		ll ans = solve(0, 0, k);
		if (k == 1) ans = (ans + mod-1) % mod;
		printf("%lld\n", ans);
	}
}
