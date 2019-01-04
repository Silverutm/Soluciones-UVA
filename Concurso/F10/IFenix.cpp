#include <iostream>
#include <cstdio>
using namespace std;
#define f(i,x,y) for(int i = x; i < y; i ++)
#define ll long long

void mmul(int c[4][4], int a[4][4], int b[4][4])
{
	int x[4][4];
	f(i, 0, 4) f(j, 0, 4)
	{
		x[i][j] = 0;
		f(k, 0, 4) x[i][j] += a[i][k] * b[k][j];
	}
	f(i,0,4) f(j,0,4) c[i][j] = x[i][j] % 10;
}

void mpow(int p[4][4], int a[4][4], ll n)
{
	int b[4][4]; f(i,0,4) f(j,0,4) b[i][j] = a[i][j], p[i][j] = i == j;
	for (; n; n >>= 1)
	{
		if (n&1) mmul(p, p, b);
		mmul(b, b, b);
	}
}

int a[4][4] = {1, 1, 1, 1,  0, 4, 7, 7,  0, 5, 6, 6,  0, 9, 1, 0};
int v[4];
int p[4][4];

int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		ll n;
		scanf("%lld %d%d%d", &n, &v[1], &v[2], &v[3]);
		v[0] = 9*(v[1] + v[2] + v[3]) % 10;

		mpow(p, a, (n+1) % 15);
//		f(i, 0, 4) f(j, 0, 4) cout << p[i][j] << char(j+1==4?10:32);
		int ans = 0;
		f(i, 0, 4) ans += p[0][i] * v[i];
		printf("%d\n", ans % 10);
	}
}

