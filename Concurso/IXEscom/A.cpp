#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define pb push_back
#define f first
#define s second
#define tam 100005
int n, k, m, a;//, casas;
vi casas_del_depto[tam];//, deptos_de_casa[tam];
//map<int, vi > deptos_de_casa;

int tot;
void rango(int z,int i, int d)
{
    if (z<i or z>d)
        while(true);
}

int main()
{
    int res = 1000000007;
    int i, j, t;
    //casas = 0;
    scanf("%d %d", &n, &k);
    //rango(k, 0, 1000000000);          //////////////
    //rango(n, 2, 100000);            ////////////////
    for ( i=1; i<=n; ++i)       //depto
    {
        scanf("%d", &m);
        //tot += m;                   ///////////////
        //rango(m, 1, 100000);        //////////////        
        for ( j=1; j<=m; ++j)   //casas
        {
            scanf("%d", &a);
            //rango(a, 1, 1000000000);          //////////////
            //casas = max(casas, a);
            casas_del_depto[i].pb(a);
            if (a<=n and a!=i)
                res = min(res, abs(i-a));
            //deptos_de_casa[a].pb(i);
        }
    }
    //rango(tot, 1, 100000);          //////////////

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

    //for (j=1; j<=casas; ++j)
    /*for (auto &par:deptos_de_casa)
    {
        //t = deptos_de_casa[j].size();
        t = par.s.size();
        for ( i=1; i<t; ++i)
        {
            //res = min( res, deptos_de_casa[j][i] - deptos_de_casa[j][i - 1] );          
            res = min( res, par.s[i] - par.s[i - 1] );          
        }
    }*/
    ll r = res;
    printf("%lld", r*r*k);
    return 0;
}