#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define tam 100005
typedef vector<int> vi;
vi Lista[tam];
bitset<tam> visitado;
int mini, maxi, dife;

void f(int u)
{
    visitado[u] = true;
    mini = min(mini, u);
    maxi = max(maxi, u);

    for (int v:Lista[u])
        if (not visitado[v])
            f(v);
}

int maximumDifference(int g_nodes, vi g_from, vi g_to)
{    
    int i;
    for ( i = 0; i<g_to.size(); ++i)
    {
        Lista[ g_from[i] ].pb( g_to[i] );
        Lista[ g_to[i] ].pb( g_from[i] );
    }

    dife = -1;
    for ( i = 1; i<=g_nodes; ++i)
        if (not visitado[i])
        {
            mini = tam; maxi = -1;
            f(i);
            dife = max(dife, maxi - mini);
        }
    
    return dife;
}

int main()
{
    int n, m, a, b;
    cin>>n>>m;
    vi v1, v2;
    while (m--)
    {
        cin>>a>>b;
        v1.pb(a);
        v2.pb(b);

    }
    cout<<maximumDifference(n, v1, v2)<<"\n";
    return 0;
}
