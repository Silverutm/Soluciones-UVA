#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

bitset<1000010> bs;
vector<Long> primes;

void criba(Long upper) {
	Long tam = upper + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (Long i = 2; i <= tam; ++i) if (bs[i]) {
		for (Long j = i*i; j <= tam; j += i) bs[j] = 0;
		primes.push_back(i);
	}
}
/*
Long expBin(Long a, Long n) {
	Long resultado = 1;
	for (; n; n >>= 1) {
		if (n & 1) resultado =
			(resultado * a);
		a = (a * a);
	}
	return resultado;
}
*/

Long sumDiv(Long N) {
	Long PF_idx = 0, PF = primes[PF_idx], ans = 1;
	while (PF * PF <= N) {
		Long power = 0;
		
		Long acc = 1;
		while (N % PF == 0) { 
			N /= PF; power++;
			acc *= PF;
		}
		acc *= PF;

		ans *= (acc - 1) / (PF - 1);
		PF = primes[++PF_idx];
	}

	if (N != 1) ans *= (N*N - 1) / (N - 1);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	criba(1000000);

	int t;
	cin >> t;
	while (t--) {
		Long n;
		cin >> n;
		
		Long acc = sumDiv(n) - n;
		//cout << acc << endl << endl;

		if (acc < n)
			cout << "deficient\n";
		else if (acc == n)
			cout << "perfect\n";
		else if (acc > n)
			cout << "abundant\n";

	}
	return 0;
}

