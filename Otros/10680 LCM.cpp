#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[1000005];
int main()
{
    f[1] = 1; f[2] = 2; f[3] = 6;
    
    
    
    ll n;
    while (scanf("%lld", &n) == 1)
        printf("%lld", f[n]);
    return 0;
}