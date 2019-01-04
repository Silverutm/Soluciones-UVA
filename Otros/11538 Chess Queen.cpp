#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tam 1000005
ll t[tam];
ll f(int n)
{
    if (n<=3) return 0;
    ll &res = t[n];
    if ( res != -1) return res;
    res = 0;    
    if (n&1)
    {
        z = n - 3;
        res = z / 2 * (2 + z) / 2;
    }
    else //par
    {
        int z = n - 3;        
        res = (z + 1) / 2 * (1 + z) / 2;        
    }
    return res = res + f(n-1);
}

int main()
{
    memset(t, -1, sizeof t);
    t[0] = 1;
    int n;    
    while(cin>>n)
    {               
        cout<<f(n)<<"\n";        
    }
    return 0;
}