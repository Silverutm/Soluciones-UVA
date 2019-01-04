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


int main() { _
	int N;
	long long D;
	string s;
	while(cin >> N >> D >> s) {
	string aux;
	string top, mid, bottom;
	getline(cin, aux);
	getline(cin, top);
	getline(cin, mid);
	getline(cin, bottom);
	cout << top << endl;
	D = (s[0] == 'L' ? 1 : -1) * 2*D;
	D = (D%(2*N) + 2*N) % (2*N);
	FOR(i, D, 2*N) cout << mid[i];
	FOR(i, 0, D) cout << mid[i];
	cout << "|";
	cout << endl;
	cout << bottom;
	cout << endl;
	}
}
