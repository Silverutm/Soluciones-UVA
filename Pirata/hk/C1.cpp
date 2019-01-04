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

#define maxN 100000

int N, tree[2*maxN];

int query(int l, int r) {
	int ans = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ans |= tree[l++];
		if (r & 1) ans |= tree[--r];
	}
	int ret = 0;
	while (ans) {
		if (ans & 1) ret++;
		ans >>= 1;
	}
	return ret;
}

int main() {
	int temp, l, r, Q;
	while (scanf("%d", &N) != EOF) {
		FOR(i, 0, N) {
			scanf("%d", &temp);
			tree[i + N] = 1 << temp;
		}
		for (int i = N - 1; i; i--) tree[i] = tree[i << 1] | tree[i << 1 | 1];
		scanf("%d", &Q);
		while (Q--) {
			scanf("%d %d", &l, &r);
			printf("%d\n", query(l-1, r));
		}
	}
	return 0;
}
