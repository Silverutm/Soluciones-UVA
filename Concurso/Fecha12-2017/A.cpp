#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    if(b == 0)
	        return a;
    return gcd(b, a % b);
}

int main()
{
    ll n, a, b, g;
    while (scanf("%lld", &n)==1)
    {
        a = 3 * n; b = 2 * n + 1;
        if (a%b == 0) printf("%lld\n", a/b);
        else
        {
            g = gcd(a, b);
            printf("%lld/%lld\n", a/g, b/g);
        }
    }
}