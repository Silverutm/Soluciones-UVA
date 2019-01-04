#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(int);
ll p(int);
ll a_f[30], a_p[30];

ll f(int k)
{
    ll &r = a_f[k];
    //if (r!=-1) return r;

    if (k == 1) return r = 3;
    if (k == 2) return r = 8;

    return r = 2*p( k - 1 ) + 3 * ( f(k - 1) - p(k - 1) );
}

ll p(int k)
{
    ll &r = a_p[k];
    //if (r!=-1) return r;
    
    if (k == 1) return r = 1;    

    return r =  ( f(k) - 2*p(k - 1) )/3;
}

int main()
{    
    memset(a_f, -1, sizeof a_f);
    memset(a_p, -1, sizeof a_p);
    for (int i=1; i<10; ++i)
        f(i);

    for (int i=1; i<10; ++i)
        cout<<i<<" "<<a_f[i]<<endl;
    cout<<endl;
    for (int i=1; i<10; ++i)
        cout<<i<<" "<<a_p[i]<<endl;
    return 0;
}