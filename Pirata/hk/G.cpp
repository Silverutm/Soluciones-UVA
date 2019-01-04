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

#define maxN 1001

long double ex[maxN], ey[maxN];

int main() {
	int xl, yl, xr, yr;
	while (scanf("%d %d %d %d", &xl, &yl, &xr, &yr) != EOF) {
		xr -= xl;
		yr -= yl;
		double ans = xr*xr / 6. + yr*yr / 6.;
		printf("%.9f\n", ans);
	}
	return 0;
}
