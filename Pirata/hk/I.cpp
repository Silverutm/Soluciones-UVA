//610 A
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define aint(x) (x).begin(), (x).end()
using namespace std; typedef long long ll; typedef pair<int, int> ii; typedef vector<int> vi; typedef vector<ii> vii; typedef vector<vi> vvi;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct Edge {
  int to, weight;
  Edge(int to, int weight = 1) : to(to), weight(weight) {}
};
struct Graph {
  int V; bool undirected;
  vector<vector<Edge> > edges;
  Graph(int v, bool undirected) : V(v), undirected(undirected) { edges.assign(V, vector<Edge>()); }
  void connect(int from, Edge edge) {
    edges[from].pb(edge);
    if(undirected) {
      int aux = edge.to;
      edge.to = from;
      edges[aux].pb(edge);
    }
  }
};

struct LCA {
  vi order, height, index, st;
  int minIndex(int i, int j) {
    return height[i] < height[j] ? i : j;
  }
  LCA(Graph &g, int root) {
    index.assign(g.V, -1);
    dfs(g, root, 0);
    st.assign(height.size()*2, 0);
    FOR(i, 0, height.size())
      st[height.size() + i] = i;
    for(int i = height.size()-1; i; i--)
      st[i] = minIndex(st[i<<1], st[i<<1|1]);
  }
  void dfs(Graph &g, int cv, int h) {
    index[cv] = order.size();
    order.pb(cv), height.pb(h);
    FORC(g.edges[cv], edge)
      if(index[edge->to] == -1) {
        dfs(g, edge->to, height.back() + 1);
        order.pb(cv), height.pb(h);
      }
  }
  int query(int i, int j) {
    int from = index[i], to = index[j];
    if (from > to) swap(from, to);
    int idx = from;
    for(int l = from + height.size(), r = to + height.size() + 1; l < r; l >>= 1, r >>= 1) {
      if (l&1) idx = minIndex(idx, st[l++]);
      if (r&1) idx = minIndex(idx, st[--r]);
    }
    return order[idx];
  }
};

int multiply(int a, int b) {
	return __gcd(a, b);
}

struct SegmentTree {
  vi tree;
  int N;
  SegmentTree(vi &values) {
    tree.assign(values.size()*2, 0);
    N = values.size();
    FOR(i, 0, N)
      tree[i + N] = values[i];
    for(int i = N - 1; i; i--)
      tree[i] = multiply(tree[i<<1], tree[i<<1|1]);
  }
  void set(int index, int value) {
    tree[index + N] = value;
    for(int i = (index + N)>>1; i; i >>= 1)
      tree[i] = multiply(tree[i<<1], tree[i<<1|1]);
  }
  int query(int from, int to) {
    int ans = tree[N+from];
    for(int l = N + from, r = N + to; l < r; l >>= 1, r >>= 1) {
	  if (l&1) ans = multiply(ans, tree[l++]);
	  if (r&1) ans = multiply(ans, tree[--r]);
    }
    return ans;
  }
};

vi parent;

struct HeavyLightDecomposition {
  vector<SegmentTree> sts;
  LCA *lca;
  vector<vi> lists;
  vi values, listIndex, posIndex, treeSizes;
  HeavyLightDecomposition(Graph &g, vi r) {
    lca = new LCA(g, 0);
    listIndex = posIndex = parent = treeSizes = vi(g.V, -1);
    getTreeSizes(g, 0);
    values = vi(r.begin(), r.end());
    makeLists(g, 0, -1);
    FORC(lists, list) {
      vi v;
      FORC(*list, it)
		  v.pb(r[*it]);
      sts.pb(SegmentTree(v));
    }
  }
  ~HeavyLightDecomposition() { delete lca; }
  int getTreeSizes(Graph &g, int cv) {
    treeSizes[cv] = 1;
    FORC(g.edges[cv], edge) if(edge->to != parent[cv])
      parent[edge->to] = cv, treeSizes[cv] += getTreeSizes(g, edge->to);
    return treeSizes[cv];
  }
  void makeLists(Graph &g, int cv, int listNum) {
    if(listNum == -1)
      listNum = lists.size(), lists.pb(vi());
    listIndex[cv] = listNum;
    posIndex[cv] = lists[listNum].size();
    lists[listNum].pb(cv);
    int MAX = -1;
    FORC(g.edges[cv], edge) if(edge->to != parent[cv]) {
      if(MAX == -1 || treeSizes[edge->to] > treeSizes[MAX]) MAX = edge->to;
    }
    FORC(g.edges[cv], edge) if(edge->to != parent[cv])
      makeLists(g, edge->to, edge->to == MAX ? listNum : -1);
  }
  int query(int from, int to) {
    if (from == to) return values[from];
    int anc = lca->query(from, to), posLeft, posRight;
	int x, y;
    int result = multiply(multiply(queryToAncestor(from, anc, posLeft), queryToAncestor(to, anc, posRight)), values[anc]);
    if(posLeft < posRight) swap(posLeft, posRight);
    result = multiply(result, sts[listIndex[anc]].query(posIndex[anc], posRight+1));
    result = multiply(result, sts[listIndex[anc]].query(posRight, posLeft+1));
    return result;
  }
  int queryToAncestor(int from, int anc, int &posInAncestorList) {
    int result = values[from], left = from;
    while(listIndex[left] != listIndex[anc]) {
      result = multiply(result, sts[listIndex[left]].query(0, posIndex[left]+1));
      left = parent[lists[listIndex[left]][0]];
    }
    posInAncestorList = posIndex[left];
    result = multiply(result, sts[listIndex[left]].query(posInAncestorList, posIndex[anc]+1));
    return result;
  }
  void set(int index, int value) {
    sts[listIndex[index]].set(posIndex[index], value);
	values[index] = value;
  }
};

int N;

struct Brute {
	Graph g;
	vi values;
	Brute(Graph &g, vi values):  g(g), values(values) {
	}
	int query(int from, int to) {
		vi visited(N, 0);
		visited[from] = 1;
		return dfs(from, visited, values[from], to).se;
	}
	ii dfs(int cv, vi &visited, int acc, int to) {
		if (cv == to) {
			return ii(1, multiply(acc, values[to]));
		}

		FORC(g.edges[cv], edge) {
			if (!visited[edge->to]) {
				visited[edge->to] = 1;
				ii ans = dfs(edge->to, visited, multiply(acc, values[cv]), to);
				if (ans.first) return ans;
			}
		}

		return ii();
	}
	void set(int index, int value) {
		values[index] = value;
	}
};

int main() { _
	cin >> N;
	vi val(N, 0);
	FOR(i, 0, N)
		cin >> val[i];

	Graph g(N, true);
	FOR(i, 0, N-1) {
		int a, b;
		cin >> a >> b;
		g.connect(a, Edge(b));
	}

	HeavyLightDecomposition hld(g, val);

	int Q;
	cin >> Q;
	FOR(i, 0, Q) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 1) {
			int t2 = hld.query(a, b);
			cout << t2 << endl;
		} else {
			hld.set(a, b);
		}
	}
}
