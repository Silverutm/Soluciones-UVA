#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef vector <int> vi;
typedef long long ll;
typedef pair <int , int> ii;


int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		ll x;
		scanf("%lld", &x);
		ll res = 3 * x * x + 2;
		printf("%lld\n", res);
	}
	return 0;
}