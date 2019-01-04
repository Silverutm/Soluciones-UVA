#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{    
    int t;
    ll n, raiz, res;
    cin>>t;
    
    //double gamma=0.57721;
    while (t--)
    {
        cin>>n;
        raiz = sqrt(n);
        //a(n) = 2*(Sum_{i=1..floor(sqrt(n))} floor(n/i))
        res = 0;
        for (int i = 1; i<=raiz; ++i)
            res += n/i;
        res = res * 2 - raiz*raiz;
        cout<<res<<"\n";
        //raiz = sqrt(n);
        //cout<<(ll)floor(n * ( log(n) + 2*gamma - 1 ) + log(n)*pow(n,1.0/3) )<<"\n";
        //cout<<f(raiz)*2 - raiz*raiz<<"\n";
    }
    
    
    
    return 0;
}