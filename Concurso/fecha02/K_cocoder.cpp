#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
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

int main() {
	int K, R;
	cout << fixed << setprecision(5);
	while (cin >> K >> R) {
		R = (1 << K) - R;
		double ans = 0, prob = 1, div = 1 << K;
		FOR(i, 1, K+1) {
			double p2 = 1;
			FOR(j, 0, 1 << i-1) {
				prob *= R-- / --div;
			}
			if(R>0) FOR(j, 0, 1 << i) {
				p2 *= (R - j) / (div-j-1);
			}
			else p2 = 0;
			ans += i*(prob)*(1 - p2);
		}
		cout << ans << endl;
	}
	return 0;
}
