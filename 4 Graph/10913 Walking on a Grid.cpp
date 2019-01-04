#include <bits/stdc++.h>
#define tam 80
#define pb push_back
#define INF 1000000000000000LL
using namespace std;
typedef vector <int> vi;
typedef long long ll;

ll tabla[tam][tam][10][5]; 
int it[tam][tam][10][5], iit;
int n, K, matriz[tam][tam];
#define cen 0
#define der 1
#define izq 2
ll f(int y, int x, int k, int dir)
{
    if (y<1 or y>n or x<1 or x>n) return -INF;
    if (matriz[y][x]<0) ++k;
    if (k>K) return -INF;

    ll &res = tabla[y][x][k][dir];
    if ( iit == it[y][x][k][dir] ) return res;
    it[y][x][k][dir] = iit;
    
    res = -INF;
    if (y==n and x==n)
        return res = matriz[y][x];
    if (dir == cen)        
    {
        res = max(res, f(y, x + 1, k, der));
        res = max(res, f(y, x - 1, k, izq));
    }
    else if (dir == izq)
        res = max(res, f(y, x - 1, k, izq));
    else if (dir == der)
        res = max(res, f(y, x + 1, k, der));
    
    res = max(res, f(y + 1, x, k, cen));
    //cout<<y<<"  "<<x<<"  "<<k<<"   "<<res + matriz[y][x]<<"\n";
    return res = res + matriz[y][x];    
}

int main()
{
    int i, j;
    ll r;
    while (cin>>n>>K and (n or K) )
    {        
        ++iit;
        memset(tabla, -1, sizeof tabla);
        for (i=1;i<=n; ++i)
            for (j=1;j<=n; ++j)
            {
                cin>>matriz[i][j];
                //cout<<matriz[i][j]<<" ";
            }//cout<<"\n\n\n";

        r = f(1,1, 0, cen);
        cout<<"Case "<<iit<<": ";
        if (r<-100000000000LL)
            cout<<"impossible\n";
        else
            cout<<r<<"\n";
    }
    return 0;
}