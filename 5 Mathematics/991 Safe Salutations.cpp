#include <bits/stdc++.h>
using namespace std;

int t[25];
int f(int n)
{
    int &res = t[n];
    if ( res != -1) return res;
    
    if (n&1) return res = 0;    
    res = 0;
    for (int i = 2; i <= n; ++i)
        res += f(i - 2) * f( n - i );
    return res;
}

int main()
{
    memset(t, -1, sizeof t);
    t[0] = t[2] = 1;
    int n;
    bool imp = false;
    while(cin>>n)
    {
        n <<= 1;
        if (imp) cout<<"\n";
        cout<<f(n)<<"\n";
        imp = true;
    }
    return 0;
}