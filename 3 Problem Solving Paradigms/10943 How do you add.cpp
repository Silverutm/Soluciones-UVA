#include <bits/stdc++.h>
using namespace std;
int tabla[105][105];

int f(int n, int k)
{
    if (k == 1 ) return 1;
    int &res = tabla[n][k];
    if (res!=-1) return res;
    res = 0;
    for (int i=0; i<=n; ++i)
        res = (res + f(i, k - 1)) % 1000000; 
    return res;
}

int main()
{
    memset(tabla, -1 ,sizeof tabla);
    int n, k;
    while (cin>>n>>k and n)
        cout<<f(n,k)<<"\n";
    return 0;
}