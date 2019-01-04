//610 A
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(decltype((cont).begin()) it=(cont).begin(); it!=(cont).end(); it++)
#define RFORC(cont, it) for(decltype((cont).rbegin()) it=(cont).rbegin(); it!=(cont).rend(); it++)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define mt make_tuple
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std; typedef long long ll; typedef pair<int, int> ii; typedef vector<int> vi; typedef vector<ii> vii; typedef vector<vi> vvi;

int op(int a, int b) {
	if (a == -1 || b == -1) return a == -1 ? b : a;
	return __gcd(a, b);
}

struct SegmentTree {
	vi tree;
	int N;
	SegmentTree(vi &values) {
		tree.assign(values.size()*2, 0);
		N = values.size();
		for(int i = 0; i < N; i++)
			tree[i + N] = values[i];
		for(int i = N - 1; i; i--)
			tree[i] = op(tree[i<<1], tree[i<<1|1]);
	}
	void set(int index, int value) {
		tree[index + N] = value;
		for(int i = (index + N)>>1; i; i >>= 1)
			tree[i] = op(tree[i<<1], tree[i<<1|1]);
	}
	int query(int from, int to) {
		int ans = tree[N+from];
		for(int l = N + from, r = N + to + 1; l < r; l >>= 1, r >>= 1) {
			if (l&1) ans = op(ans, tree[l++]);
			if (r&1) ans = op(ans, tree[--r]);
		}
		return ans;
	}
};

struct HeavyLightDecomposition {
	vector<SegmentTree> sts;
	vi whichList, posInList, treeSize, parent, listDepth;
	vvi lists;
	HeavyLightDecomposition(vvi &g, vi &values) {
		whichList = posInList = treeSize = parent = vi(g.size(), -1);
		getTreeSize(g, 0);
		makeLists(g, 0, -1, -1);
		for(auto &list: lists) {
			vi v;
			for(auto i: list) v.pb(values[i]);
			sts.pb(SegmentTree(v));
		}
	}
	int getTreeSize(vvi &g, int v) {
		treeSize[v] = 1;
		for(auto u: g[v]) if (u != parent[v])
			parent[u] = v, treeSize[v] += getTreeSize(g, u);
		return treeSize[v];
	}
	void makeLists(vvi &g, int v, int listIndex, int depth) {
		if(listIndex == -1) listIndex = lists.size(), lists.pb(vi()), listDepth.pb(++depth);
		whichList[v] = listIndex;
		posInList[v] = lists[listIndex].size();
		lists[listIndex].pb(v);
		int heavyChild = -1;
		for(auto u: g[v]) if (u != parent[v] && (heavyChild == -1 || treeSize[u] > treeSize[heavyChild]))
			heavyChild = u;
		for(auto u: g[v]) if (u != parent[v])
			makeLists(g, u, u == heavyChild ? listIndex : -1, depth);
	}
	int query(int l, int r) {
		if (listDepth[whichList[l]] < listDepth[whichList[r]]) swap(l, r);
		int ans = -1, lList;
		while(listDepth[lList = whichList[l]] > listDepth[whichList[r]])
			ans = op(ans, sts[lList].query(0, posInList[l])), l = parent[lists[lList][0]];
		while(whichList[l] != whichList[r]) {
			ans = op(ans, op(sts[whichList[l]].query(0, posInList[l]), sts[whichList[r]].query(0, posInList[r])));
			l = parent[lists[whichList[l]][0]], r = parent[lists[whichList[r]][0]];
		}
		return ans = op(ans, sts[whichList[l]].query(min(posInList[l], posInList[r]), max(posInList[l], posInList[r])));
	}
	void set(int u, int value) { sts[whichList[u]].set(posInList[u], value); }
};

int main() { _
	int N;
	cin >> N;
	vi val(N, 0);

	FOR(i, 0, N)
		cin >> val[i];

	vvi g(N, vi());
	FOR(i, 0, N-1) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}

	HeavyLightDecomposition hld(g, val);

	int Q;
	cin >> Q;
	FOR(i, 0, Q) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 1) cout << hld.query(a, b) << endl;
		else hld.set(a, b);
	}
}
