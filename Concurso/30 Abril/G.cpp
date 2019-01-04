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

#define maxN 100

struct Edge {
	int to, cost;
	bool operator <(const Edge &r) const {
		return cost > r.cost || cost == r.cost&&to < r.to;
	}
};

vector<Edge> edges[maxN];
int d[maxN], from1[maxN], from2[maxN];

int main() {
	int N, M, a, b, t;
	while (cin >> N >> M) {
		FOR(i, 0, N) {
			edges[i].clear();
			d[i] = INF;
		}
		FOR(i, 0, M) {
			cin >> a >> b >> t;
			a--, b--;
			edges[a].push_back(Edge{ b, t });
			edges[b].push_back(Edge{ a, t });
		}
		queue<Edge> q;
		d[0] = 0;
		q.push(Edge{ 0, 0 });
		while (!q.empty()) {
			int f = q.front().to;
			q.pop();
			FOR(i, 0, edges[f].size()) {
				int next = edges[f][i].to, cost = edges[f][i].cost;
				if (d[next] > d[f] + cost) {
					d[next] = d[f] + cost;
					from1[next] = f;
					q.push(Edge{next, d[next]});
				}
			}
		}
		memset(from2, -1, sizeof(from2));
		int s = N - 1;
		ll ans = d[N - 1];
		cout<<ans<<endl;
		while (s) {
			from2[s] = from1[s];
			s = from1[s];
		}
		q.push(Edge{ 0, 0 });
		FOR(i, 0, N) d[i] = INF;
		d[0] = 0;
		while (!q.empty()) {
			int f = q.front().to;
			q.pop();
			FOR(i, 0, edges[f].size()) {
				int next = edges[f][i].to, cost = edges[f][i].cost;
				if (from2[f] == next) {
					cost = -cost;
				}
				if (from2[next] == f) {
					continue;
				}
				if (d[next] > d[f] + cost) {
					d[next] = d[f] + cost;
					q.push(Edge{ next, d[next] });
				}
			}
		}
		for (int i=0; i<N; ++i)
			cout<<from1[i]<<" ";
		cout<<endl;
		for (int i=0; i<N; ++i)
			cout<<from2[i]<<" ";
		cout<<endl;
		//cout<<d[1]<<endl;
		cout << ans+d[N-1] << endl<<endl;
	}
	return 0;
}
