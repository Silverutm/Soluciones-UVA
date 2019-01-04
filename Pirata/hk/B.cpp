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
#define all(x) (x).begin(), (x).end()
using namespace std; typedef long long ll; typedef pair<int, int> ii; typedef vector<int> vi; typedef vector<ii> vii; typedef vector<vi> vvi;
using namespace __gnu_pbds;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define maxN 600000

int N, M;
ordered_set tree2[2 * maxN];

int getVal(int n, int s) {
	return tree2[n].order_of_key(ii(s, INF));
}

int query(int l, int r, int s) {
	int ret = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret += getVal(l++, s);
		if (r & 1) ret += getVal(--r, s);
	}
	return ret;
}

int main() {
	int t, l, r, s;
	while (scanf("%d %d", &N, &M) != EOF) {
		FOR(i, 0, 2 * N) tree2[i].clear();
		FOR(i, 0, M) {
			scanf("%d %d %d", &t, &l, &r);
			if (!t) {
				l += N;
				ii tt;
				if (tree2[l].size()) {
					tt = *tree2[l].begin();
					int tl = l;
					tree2[tl].clear();
					while (tl >>= 1) {
						tree2[tl].erase(tt);
					}
				}
				tt = ii(r, l - N);
				tree2[l].insert(tt);
				while (l >>= 1) {
					tree2[l].insert(tt);
				}
			}
			else {
				scanf("%d", &s);
				printf("%d\n", query(l, r + 1, s));
			}
		}
	}
	return 0;
}
