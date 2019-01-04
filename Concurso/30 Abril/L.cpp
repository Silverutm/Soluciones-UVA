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

#define maxN 100000
#define maxLog 20

struct Data {
	ll id, h, l;
};

struct Edge {
	int to, h, l;
};

vector<Edge> edges[maxN];
Data mem[maxN][maxLog];
int h[maxN];

void dfs(int n, int p, int hh) {
	h[n] = hh;
	FOR(i, 0, edges[n].size()) {
		int next = edges[n][i].to;
		if (next == p) continue;
		dfs(next, n, hh+1);
		mem[next][0] = Data{ n, edges[n][i].h, edges[n][i].l };
	}
}

Data dp(int n, int k) {
	if (n == -2) return Data{ -2, 0, 0 };
	if (~mem[n][k].id) return mem[n][k];
	Data t1 = dp(n, k - 1);
	Data t2 = dp(t1.id, k - 1);
	mem[n][k].id = t2.id;
	mem[n][k].l = t1.l + t2.l;
	mem[n][k].h = max(t1.h, t2.h);
	return mem[n][k];
}

ll LCA(int a, int b) {
	if (h[a] < h[b]) swap(a, b);
	int diff = h[a] - h[b], c=0;
	ll bh = 0, ls = 0;
	while (diff) {
		if (diff & 1) {
			Data t = dp(a, c);
			a = t.id;
			ls += t.l;
			bh = max(bh, t.h);
		}
		diff >>= 1;
		c++;
	}
	if (a == b) return ls*bh;
 	c = maxLog - 1;
	while (c>=0) {
		Data t1 = dp(a, c), t2=dp(b, c);
		if (t1.id != t2.id) {
			a = t1.id;
			b = t2.id;
			ls += t1.l + t2.l;
			bh = max(bh, max(t1.h, t2.h));
		}
		c--;
	}
	ls += mem[a][0].l + mem[b][0].l;
	bh = max(bh, max(mem[a][0].h, mem[b][0].h));
	return ls*bh;
}

int main() {
	int P, a, b, h, l, Q;
	while (scanf("%d", &P)!=EOF) {
		FOR(i, 0, P) edges[i].clear();
		FOR(i, 0, P - 1) {
			scanf("%d %d %d %d", &a, &b, &h, &l);
			a--, b--;
			edges[a].push_back(Edge{ b, h, l });
			edges[b].push_back(Edge{ a, h, l });
		}
		memset(mem, -1, sizeof(mem));
		dfs(0, -1, 0);
		mem[0][0] = Data{ -2, 0, 0  };
		scanf("%d", &Q);
		FOR(i, 0, Q) {
			scanf("%d %d", &a, &b);
			a--, b--;
			printf("%lld\n", LCA(a, b));
		}
		break;
	}
	return 0;
}
