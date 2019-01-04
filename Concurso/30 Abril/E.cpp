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

#define maxN 1000001

char S[maxN];

int main() {
	int Q, a, b;
	while (scanf("%s %d", S, &Q)!=EOF) {
		int len = strlen(S);
		FOR(i, 0, Q) {
			scanf("%d %d", &a, &b);
			a = (a + b - 2) % len;
			printf("%c\n", S[a]);
		}
	}
	return 0;
}
