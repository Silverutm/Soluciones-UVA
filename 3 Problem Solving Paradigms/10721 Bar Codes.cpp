#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m;
ll tabla[55][55][55];

ll f(int n, int k)
{
    if (n<0) return 0;

    ll &res = tabla[n][m][k];
    if (res != -1 ) return res;    
    
    if (n==0 and k==0) return res = 1;
    if (n==0 or k==0) return res = 0;
    
    res = 0;    
    for (int i=1; i<=m; ++i)
        res += f(n - i, k - 1); 
    return res;
}

int main()
{
    memset(tabla, -1 ,sizeof tabla);
    int n, k;
    while (cin>>n>>k>>m)
        cout<<f(n, k)<<"\n";
    return 0;
}