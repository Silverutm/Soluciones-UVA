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

#define MOD 10000000000LL

int main() {
	unsigned long long N;
	while (cin >> N&&N) {
		unsigned long long ans;
		if (N & 1) {
			ans = (N + 1) / 2 * (N + 1) / 2 % MOD;
			ans = ans*N % MOD*N % MOD;
		}
		else {
			ans = N / 2 * N / 2%MOD;
			ans = ans*(N + 1) % MOD*(N + 1) % MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
