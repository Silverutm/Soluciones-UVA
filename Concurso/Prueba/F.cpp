#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
using namespace std;
typedef pair <int, int> ii;
typedef vector < ii > vii;
typedef long long ll;
#define mod 1000000007
int main()
{
	ll n, k, res=0LL, a;
	int i;
	scanf("%lld %lld", &n, &k);
	for (i=0; i<n; ++i)
	{
		scanf("%lld", &a);
		//res = (res+a)%mod;
		res+=a;
	}
	res %=mod;
	for (i=0; i<k; ++i)
	{
		res= res*(n-1) %mod;
	}
	printf("%lld\n", res);
	return 0;
}