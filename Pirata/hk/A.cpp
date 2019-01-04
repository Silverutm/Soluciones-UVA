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

#define maxN 15

char a[maxN];

int main() {
	string str;
	while (getline(cin, str)) {
		int ac = 1;
		a[0] = str[0];
		FOR(i, 1, str.length()) {
			if (str[i] == ' ') {
				a[ac++] = str[i + 1];
			}
		}
		getline(cin, str);
		int ac2 = 1;
		bool y = a[0] == str[0];
		FOR(i, 1, str.length()) {
			if (str[i] == ' ') {
				if (a[ac2++] != str[i + 1]) y = false;
			}
		}
		if (y) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
