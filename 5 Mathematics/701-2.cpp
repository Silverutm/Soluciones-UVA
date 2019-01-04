#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map <ll, int> mapa;
void meter(ll n, int pot)
{    
    int digitos = floor( log10(n) ) + 1;
    int k = (digitos-1)/2;
    while (digitos>k)
    {
        n /= 10;
        --digitos;
    }
    while (n)
    {
        if (not mapa[n])
            mapa[n] = pot;
        n /= 10;
    }
}

int main()
{
    double n;
    double l_n, l_n1, l_2_10;
    while (cin>>n)
    {
        l_n = log2(n);
        l_n1 = log2(n + 1);
        l_2_10 = log2(10);
        ll t = floor( log10(n) ) + 1;
        ll e1, e2;
        do        
        {
            ++t;
            e1 = ceil ( l_n + t * l_2_10 );
            e2 = floor ( l_n1 + t * l_2_10 );            
        }while (e1!=e2 and e1<10000000);
        cout<<e1<<"\n";        
    }
    return 0;
}