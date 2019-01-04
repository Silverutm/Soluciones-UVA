#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
typedef pair<Long, Long> ii;
typedef vector<ii> vii;

int const MAX = 5010;
Long const MOD = 1000000007;

vector<Long> divs;
int pre_aristas[MAX][MAX];
int pre_acc[MAX][MAX];

void divisores() {
	divs.assign(MAX, -1LL);
	for (Long i = 1; i < MAX; ++i)
		for (Long j = i; j < MAX; j += i)
			divs[j]++;
}

Long exp(Long a, Long n, Long m) {
	Long resultado = 1;
	for (; n; n >>= 1) {
		if (n & 1) resultado =
			(resultado * a) % m;
		a = (a * a) % m;
	}
	return resultado % m;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	divisores();

	vector<Long> fact(MAX);
	vector<Long> inv(MAX);
	fact[0] = fact[1] = 1;
	for (Long i = 2; i < MAX; ++i)
		fact[i] = (i % MOD * fact[i - 1] % MOD) % MOD;
	
	for (Long i = 0; i < MAX; ++i)
		inv[i] = exp(fact[i], MOD - 2, MOD);

	//vector<vii> pre(MAX, vii(MAX, ii(0, 1)));
	for (Long k = 1; k < MAX - 7; k++) 
	{
		for (Long n = 1; n < MAX - 7; n++) 
		{
			if (n == 1) 
			{
				pre_acc[n][k] = 1; 
				continue;
			}
			Long aristas = min(k, divs[n]);
			Long acc = 1;
			if (divs[n] > k) {
				Long numerador = fact[ divs[n] ];
				Long denominador = (inv[divs[n] - k] % MOD * inv[k] % MOD) % MOD;
				acc = (numerador % MOD * denominador % MOD) % MOD;
			}
			pre_aristas[n][k] = (aristas % MOD + pre_aristas[n - 1][k] % MOD) % MOD;
			pre_acc[n][k] = (acc % MOD * pre_acc[n - 1][k] % MOD) % MOD;
		}
	}
	int t;
	cin >> t;
	while (t--) {
		Long n, k;
		cin >> n >> k;
		cout << pre_aristas[n][k] <<  ' ' << pre_acc[n][k] << '\n';
	}
	return 0;
}
/*
3
4 2 
5 3
6 2
*/