#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const lli MOD = 1000000007LL; 
lli TINV, SINV;

lli Multiplicar(lli a, lli b) {
	lli res = 0, p = a;
	for (; b; b >>= 1) {
		if (b & 1) res = (res + p) % MOD;
		p = (p + p) % MOD;
	} 
	return res;
}

lli euc (lli a, lli b, lli& x, lli& y, lli mod = 0) {
	if (!b) { x = 1LL, y = 0; return a; }
	lli gcd = euc(b, a % b, x, y, mod);
	x = !mod? x - y * (a / b):
		(mod + x - (y * (a / b)) % mod) % mod;
	swap(x, y);
	return gcd;
}

lli F(lli xi) {
	return Multiplicar(((Multiplicar((Multiplicar(xi, xi + 1LL)), TINV)) + (Multiplicar((Multiplicar(xi, Multiplicar(xi + 1LL, ( Multiplicar(2LL, xi) + 1LL) % MOD ) )), SINV))) % MOD, TINV);
}

int main() {
	
	cin.tie(0); ios_base::sync_with_stdio(0);

	lli x, y = 0;

	euc(2LL, MOD, TINV, y, MOD);
	y = 0;
	euc(6LL, MOD, SINV, y, MOD);

	int T;

	cin >> T;
	
	for (int i = 0; i < T; ++i) {
		lli N;
		cin >> N;
		lli A = (N / 2LL);
		
		lli sumb = Multiplicar(Multiplicar(A + 1LL, A + 2LL), TINV);
		lli suma = Multiplicar(Multiplicar(A + 1LL, A), TINV);
		lli sume = Multiplicar(Multiplicar(N - A - 1LL, N - A), TINV);

		lli ans = Multiplicar(N - A, sumb);
		ans = (ans + (Multiplicar(N - A, Multiplicar(suma, A + 1LL)))) % MOD;
		ans = (ans + (Multiplicar(A + 1LL, Multiplicar(sume, A + 1LL)))) % MOD;
		ans = (ans + (Multiplicar(A + 1LL, F(N - A - 1LL)))) % MOD;




		cout << "Case #" << (i + 1) << ": " << ans << '\n';

	}

	return 0;
}