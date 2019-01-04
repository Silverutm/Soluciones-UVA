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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define MAXN 1000010

int main() {
	_
		vector<ll> soq(MAXN, 0);
	FOR(i, 0, MAXN) {
		soq[i] = ll(i)*i;
	}

	vector<ll> accumOdd(MAXN, 0), accumEven(MAXN, 0);

	for (int i = 1; i <= MAXN; i += 2)
		accumOdd[i] = soq[i] + (i == 1 ? 0 : accumOdd[i - 2]);

	for (int i = 2; i <= MAXN; i += 2)
		accumEven[i] = soq[i] + accumEven[i - 2];

	int N;
	while (cin >> N && N) {
		if (N & 1) {
			printf("%.10f\n", sqrt(2 * accumEven[N - 1] / double(N - 1)));
		}
		else {
			printf("%.10f\n", sqrt(2 * accumOdd[N - 1] / double(N - 1)));
		}
	}

}
