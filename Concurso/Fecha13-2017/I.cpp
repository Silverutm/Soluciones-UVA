#include <bits/stdc++.h>
using namespace std;
#define tam 200005
typedef long long ll;

map<ll,int> mapa;
int main()
{
    int i;
    ll x, y, res, n;
    while (scanf("%lld", &n) == 1)
    {
        mapa.clear();
        res = 0;
        for (i = 0; i<n; ++i)
        {
            scanf("%lld %lld", &x, &y);
            ++mapa[x-y]; ++mapa[x+y];
            res += 2*(mapa[x-y] + mapa[x+y] - 2);
        }
        printf("%.6lf\n", (double)res/(n*n));
    }
    return 0;
}