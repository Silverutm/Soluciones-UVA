#include <bits/stdc++.h>
#define f first
#define s second
#define mk make_pair
#define pb push_back
#define tam 1000003
#define mod 1000000007LL
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;


#define der 0
#define izq 1
#define aba 2
int estoy;
ll arr[tam], x, y, n;
int j;

void acomodar()
{
	ll z;
	if (estoy== aba)
	{
		x = ((j-1) - 1)<<1;
		y =  1 - (j-1);
		
		z = n - arr[j-1];
		x -= z;
	}
	else if (estoy==izq)
	{
		x = ((j-1) - 1)<<1;
		y =  1 - (j-1);
		x -= 4*j - 6 - 1;

		z = n - (arr[j-1] + 4*j - 6 - 1);
		x += z;
		y += z;
	}
	else //estoy der
	{
		x = (j - 1)<<1;
		y =  1 - j;

		z = arr[j] - n;
		x -= z;
		y += z;
	}
}

int main()
{
	//int i;
	for (ll i = 1; i < tam; ++i)
		arr[i] = 4*i*i - 8*i + 5;

	int t;	
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld", &n);
		j = lower_bound(arr, arr+tam, n) - arr;		

		if ( n < arr[j-1] + 4 * j - 6 )
			estoy = aba;
		else if (n <= arr[j] -2*j+1 )
			estoy = izq;
		else estoy = der;

		acomodar();
		printf("%lld %lld\n", x, y);
	}
	return 0;
}