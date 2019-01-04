#include <bits/stdc++.h>
#define tam 610
#define pb push_back
#define INF 2000000000
using namespace std;
typedef vector <int> vi;

//vi Lista[tam];
int d[tam], ac[tam];
int tabla[tam][tam/2];
int n;

int f(int pos, int k)
{
    if (pos == n and k == 0) return 0;
    if (pos == n or k == 0) return INF;
    int &res = tabla[pos][k];
    if ( res!= -1 ) return res;

    res = INF;
    int parcial;
    for (int i = pos + 1; i<=n; ++i)
    {
        parcial = max(ac[i] - ac[pos], f(i, k - 1));
        res = min(res, parcial);
    }
    return res;
}

int main()
{
    int k, i;
    while (cin>>n>>k)
    {
        ++k; ++n; ac[0] = 0;
        memset(tabla, -1, sizeof tabla);
        for (i=1;i<=n; ++i)
        {
            cin>>d[i];
            ac[i] = ac[i - 1] + d[i];
        }

        cout<<f(0,k)<<"\n";
    }
    return 0;
}