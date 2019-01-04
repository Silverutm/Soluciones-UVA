#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t[45];
ll f(int n)
{
    if (n<0) return 0;
    ll &res = t[n];
    if ( res != -1) return res;
        
    return res = 4*f(n - 2) + f(n - 1) + 2*f(n-3);
}

int main()
{
    memset(t, -1, sizeof t);
    t[0] = 1;
    int n, c;
    cin>>c;
    while(c--)
    {
        cin>>n;        
        cout<<f(n)<<"\n";        
    }
    return 0;
}