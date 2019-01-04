#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		lld n; cin >> n;
		lld level = sqrt(n - 1)/2;
		lld idx = 1 + 4 * level * level;
		lld x = level * 2;
		lld y = level * (-1);
		lld izq = idx + 4 * level + 1;
		lld der = idx;
		lld arr = idx + 6 * level + 2;
		if (n < izq && n >= der) {
			while (der != n)
				x--, der++;
			cout << x << ' ' << y << '\n';
			continue;
		}
		if (n < arr && n >= der) {
			x = x - (4 * level + 1);
			while (izq != n)
				x++, y++, izq++;
			cout << x << ' ' << y << '\n';
			continue;
		}
		x = 0; y = level + 1;
		while (arr != n)
			x++, y--, arr++;
		cout << x << ' ' << y << '\n';
	}
	return 0;
}
/*
15
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15

*/