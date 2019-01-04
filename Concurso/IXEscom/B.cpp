#include <iostream>
using namespace std;
int papa[200005], val[200005], pendiente[200005];
long long res;
bool par;
int main()
{
    int n, m, i, k, x, y;
    scanf("%d %d", &n, &m);
    if (n>1000 or m>1000)
        while (true);
    for (i=1; i<=n; ++i)
        scanf("%d", &val[i]);
    papa[1] = -1;
    for (i=1; i<n; ++i)
    {
        scanf("%d %d", &x, &y);
        papa[y] = x;
    }
    for (i=1; i<=m; ++i)
    {
        scanf("%d", &k);
        if (k==1)
        {
            scanf("%d %d", &x, &y);
            pendiente[x] += y;
        }
        else
        {
            scanf("%d", &x);
            res = val[x];
            par = true;
            continue ;
            while (x!=-1)
            {
                if (par) res += pendiente[x];
                else res -= pendiente[x];
                
                par = not par;
                x = papa[x];                
            }
            printf("%lld\n", res);
        }
    }
    return 0;
}