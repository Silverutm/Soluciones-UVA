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

int main() {
	string hex;
	while (cin >> hex) {
		int mod = 0;
		FOR(i, 0, hex.length()) {
			mod *= 16;
			if (hex[i] >= '0'&&hex[i] <= '9') mod += hex[i] - '0';
			else mod += hex[i] - 'A' + 10;
			mod %= 17;
		}
		if (!mod) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
