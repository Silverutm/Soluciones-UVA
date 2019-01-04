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
typedef pair<int, ll> pill;

#define maxN 5000
#define maxLog 15
#define maxE (maxN*maxN)

struct Edge {
	int a, b;
	ll cost;
	bool u;
	bool operator <(const Edge &r) const {
		return cost < r.cost;
	}
};

struct Data {
	int id;
	ll hi;
};

Edge edges[maxE];
vi sets[maxN];
vector<pill> e2[maxN];
Data mem[maxN][maxLog];
int belongs[maxN], h[maxN];

void merge(int from, int to) {
	if (sets[from].size() > sets[to].size()) swap(from, to);
	FOR(i, 0, sets[from].size()) {
		sets[to].push_back(sets[from][i]);
		belongs[sets[from][i]] = to;
	}
	sets[from].clear();
}

void dfs(int n, int p, int hh) {
	h[n] = hh;
	FOR(i, 0, e2[n].size()) {
		int next = e2[n][i].first;
		if (next == p) continue;
		dfs(next, n, hh + 1);
		mem[next][0] = Data{ n, e2[n][i].second };
	}
}


Data dp(int n, int k) {
	if (n == -2) return Data{ -2, 0 };
	if (~mem[n][k].id) return mem[n][k];
	Data t1 = dp(n, k - 1);
	Data t2 = dp(t1.id, k - 1);
	mem[n][k].id = t2.id;
	mem[n][k].hi = max(t1.hi, t2.hi);
	return mem[n][k];
}

ll LCA(int a, int b) {
	if (h[a] < h[b]) swap(a, b);
	int diff = h[a] - h[b], c = 0;
	ll bh = 0;
	while (diff) {
		if (diff & 1) {
			Data t = dp(a, c);
			a = t.id;
			bh = max(bh, t.hi);
		}
		diff >>= 1;
		c++;
	}
	if (a == b) return bh;
	c = maxLog - 1;
	while (c>=0) {
		Data t1 = dp(a, c), t2 = dp(b, c);
		if (t1.id != t2.id) {
			a = t1.id;
			b = t2.id;
			bh = max(bh, max(t1.hi, t2.hi));
		}
		c--;
	}
	bh = max(bh, max(mem[a][0].hi, mem[b][0].hi));
	return bh;
}

int main() {
	int N, M, a, b;
	ll c;
	while (scanf("%d %d", &N, &M) != EOF) {
		FOR(i, 0, N) {
			sets[i].clear();
			belongs[i] = i;
			e2[i].clear();
			sets[i].push_back(i);
		}
		FOR(i, 0, M) {
			scanf("%d %d %lld", &edges[i].a, &edges[i].b, &edges[i].cost);
			edges[i].a--, edges[i].b--, edges[i].u = false;
		}
		sort(edges, edges + M);
		ll X = 0, Y = INF;
		FOR(i, 0, M)  {
			int a = edges[i].a, b = edges[i].b;
			if (belongs[a] != belongs[b]) {
				merge(belongs[a], belongs[b]);
				e2[a].push_back(ii(b, edges[i].cost));
				e2[b].push_back(ii(a, edges[i].cost));
				edges[i].u = true;
				X += edges[i].cost;
			}
		}
		memset(mem, -1, sizeof(mem));
		dfs(0, -1, 0);
		mem[0][0] = Data{ -2, 0 };
		FOR(i, 0, M) {
			if (!edges[i].u) {
				ll cc = LCA(edges[i].a, edges[i].b);
				Y = min(Y, edges[i].cost - cc);
			}
		}
		printf("%lld %lld\n", X, Y+X);
	}
	return 0;
}
