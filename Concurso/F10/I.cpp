#include <bits/stdc++.h>
#define pb emplace_back()
#define pair <int, int> ii;
using namespace std;
typedef long long ll;
typedef vector <int > vi;


#define MAX_N 3 // increase/decrease this value as needed
struct Matrix { int mat[MAX_N][MAX_N]; };


ll gcd(ll a, ll b, ll &x, ll &y)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll r = gcd(b, a%b, y, x);
	y -= a/b*x;
	return r;
}


inline ll restmod(const ll &a, const ll &b, const ll &m)
{
	return ( ( (a % m) - (b % m) ) + m ) % m;
}

inline ll divmod(const ll &a, const ll &b, const ll &m)
{
	ll binv;
	ll y;
	gcd(b, m, binv, y);

	binv = ((binv%m)+m)%m;

	return ( (a % m) * (binv % m) ) % m;
}



Matrix matMul(Matrix a, Matrix b, int p, int q, int r) { // O(pqr)
Matrix c; int i, j, k;
for (i = 0; i < p; i++)
for (j = 0; j < r; j++)
for (c.mat[i][j] = k = 0; k < q; k++)
{c.mat[i][j] += a.mat[i][k] * b.mat[k][j];c.mat[i][j] =(c.mat[i][j]+ 10)%10;} 

return c; }

Matrix I;
Matrix fastPow(Matrix x, ll n) {
	Matrix ret = I;
	while (n) {
		if (n & 1) ret = matMul(ret, x, 3, 3, 3);
		x = matMul(x, x, 3, 3, 3);
		n >>= 1;
	}
	return ret;
}




Matrix M;

int main()
{
	int t;
	ll n;
	Matrix A, mk, inver;
	M.mat[0][0]=4;
	M.mat[0][1]=-3;
	M.mat[0][2]=-3;
	M.mat[1][0]=5;
	M.mat[1][1]=-4;
	M.mat[1][2]=-4;
	M.mat[2][0]=-1;
	M.mat[2][1]=1;
	M.mat[2][2]=0;
	I.mat[0][0]=I.mat[1][1]=I.mat[2][2]=1;

	inver.mat[0][0]=-1;
	inver.mat[0][1]=3;
	inver.mat[0][2]=-9;
	inver.mat[1][0]=1;
	inver.mat[1][1]=-3;
	inver.mat[1][2]=9;
	inver.mat[2][0]=-7;
	inver.mat[2][1]=0;
	inver.mat[2][2]=21;

	scanf("%d", &t);
	int res;
	while (t--)
	{
		scanf("%lld %d %d %d", &n, &A.mat[0][0], &A.mat[1][0], &A.mat[2][0]);
		mk=fastPow(M, n+1);
		mk.mat[0][0] =(mk.mat[0][0]+9)%10; mk.mat[1][1] =(mk.mat[1][1]+9)%10; 
			mk.mat[2][2] =(mk.mat[2][2]+9)%10;
		mk = matMul(mk, inver, 3, 3, 3);
		mk =matMul(mk, A, 3, 3, 1);
		res = divmod(((mk.mat[0][0] + mk.mat[1][0] + mk.mat[2][0])%10+10)%10, 2, 10);
		printf("%d\n", res);
		//cout<<I.mat[2][0]<<I.mat[2][1]<<I.mat[2][2]<<endl;
	}

}