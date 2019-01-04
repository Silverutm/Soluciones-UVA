#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define pb push_back
#define f first
#define s second
#define tam 100005
int n, k, m, a;
vi casas_del_depto[tam];

int main()
{
    int res = 1000000007, parcial;
    int i, j, t;
    scanf("%d %d", &n, &k);
    for ( i=1; i<=n; ++i)       //depto
    {
        scanf("%d", &m);                
        for ( j=1; j<=m; ++j)   //casas
        {
            scanf("%d", &a);            
            casas_del_depto[i].pb(a);            
        }
    }    

    for ( i=1; i<=n; ++i)
        sort( casas_del_depto[i].begin(), casas_del_depto[i].end() );
    

    for (i=1; i<=n; ++i)
    {
        t = casas_del_depto[i].size();
        for ( j=1; j<t; ++j)
        {
            res = min( res, casas_del_depto[i][j] - casas_del_depto[i][j - 1] );           
        }
    }

    for (i=1; i<n; ++i) //hacia la derecha
    {
        j = upper_bound(casas_del_depto[i+1].begin(), casas_del_depto[i+1].end(), i ) 
            - casas_del_depto[i+1].begin();
        if ( j==casas_del_depto[i+1].size() ) //no hay nadie mayor
            parcial = i - casas_del_depto[i+1][j - 1] + 1;
        else if (j==0) //soy el menor
            parcial = casas_del_depto[i+1][j] - i + 1;
        else        //estoy enmedio
        {
            parcial = min( i - casas_del_depto[i+1][j - 1] + 1, 
                            casas_del_depto[i+1][j] - i + 1  );
        }
        res = min(res, parcial);
    }

    for (i=n; i>1; --i) //hacia la izquierda
    {
        j = upper_bound(casas_del_depto[i-1].begin(), casas_del_depto[i-1].end(), i ) 
            - casas_del_depto[i-1].begin();
        if ( j==casas_del_depto[i-1].size() ) //no hay nadie mayor
            parcial = i - casas_del_depto[i-1][j - 1] + 1;
        else if (j==0) //soy el menor
            parcial = casas_del_depto[i-1][j] - i + 1;
        else        //estoy enmedio
        {
            parcial = min( i - casas_del_depto[i-1][j - 1] + 1, 
                            casas_del_depto[i-1][j] - i + 1  );
        }
        res = min(res, parcial);
    }


    ll r = res;
    printf("%lld\n", r*k );
    return 0;
}