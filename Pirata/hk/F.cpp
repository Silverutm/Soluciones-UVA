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

#define maxN 3000001
#define maxSq 2500

int sum[maxSq], ans[maxN], q[maxN], qt;

int main() {
	FOR(i, 0, maxN) ans[i] = INF;
	FOR(i, 1, maxSq) {
		sum[i] = sum[i - 1] + i;
		if (sum[i] < maxN) q[qt++] = sum[i], ans[sum[i]] = 1;
	}
	for (int qh = 0; qh < qt; qh++) {
		if (qt == maxN - 1) break;
		FOR(i, 1, maxSq) {
			int d = q[qh] + sum[i];
			if (d >= maxN) break;
			if (ans[d] == INF) {
				ans[d] = ans[q[qh]] + 1;
				q[qt++] = d;
			}
		}
	}
	int N;
	while (scanf("%d", &N)!=EOF) {
		printf("%d\n", ans[N]);
	}
	return 0;
}
