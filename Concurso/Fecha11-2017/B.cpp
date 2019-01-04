#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tam 100005

int p[tam], t[tam], quiero[tam];

int main()
{
    int n, i, j;
    scanf("%d", &n);
    for ( i = 0; i<n; ++i)
        scanf("%d", &p[i]);

    for ( i = 0; i<n; ++i)
        scanf("%d", &t[i]);

    sort(p, p+n); sort(t, t+n);

    for ( i = 0; i<n; ++i)
    {
        j = lower_bound( t, t + n, p[i]) - t;
        quiero[i] = n - j;
    }
    int resta = 0;
    ll res = 1;
    for (i=n-1; i>=0; --i)
    {
        if (quiero[i] - resta <= 0)
        { printf("0\n"); return 0; }

        res = res * (quiero[i] - resta) %1000000007;
        ++resta;
    }
    printf("%lld\n", res);
}