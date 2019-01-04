#include <bits/stdc++.h>
using namespace std;
typedef long long ll;for (int i=1; i<=n; ++i)
#define pb push_back
#define tam 100005
int n, k, m, a, casas;
vector <int> casas_del_depto[tam], deptos_de_casa[tam];

int main()
{
    int res = 1000000007;
    int i, j, t;
    casas = 0;
    scanf("%d %d", &n, &k);
    for ( i=1; i<=n; ++i)       //depto
    {
        scanf("%d", &m);        
        for ( j=1; j<=m; ++j)   //casas
        {
            scanf("%d", &a);
            casas = max(casas, a);
            casas_del_depto[i].pb(a);
            deptos_de_casa[a].pb(i);
        }
    }

    for ( i=1; i<=n; ++i)
        sort(casas_del_depto[i].begin(), casas_del_depto[i].end());
    

    for (i=1; i<=n; ++i)
    {
        t = casas_del_depto[i].size();
        for ( j=1; j<t; ++j)
        {
            res = min( res, casas_del_depto[i][j] - casas_del_depto[i][j - 1] )            
        }
    }

    for (j=1; j<=casas; ++j)
    {
        t = deptos_de_casa[j].size();
        for ( i=1; i<t; ++i)
        {
            res = min( res, deptos_de_casa[j][i] - deptos_de_casa[j][i - 1] )            
        }
    }
    ll r = res;
    printf("%lld\n", r*r*k);
    return 0;
}