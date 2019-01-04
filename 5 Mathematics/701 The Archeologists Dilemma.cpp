#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
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
    ll n = 1<<6;
    for (int i=7; i<64; ++i)
    {
        n <<= 1;
        meter(n, i);
    }
    while (cin>>n)
    {
        int pot = mapa[n];
        if (pot)
            cout<<pot<<"\n";
        else cout<<"no power of 2\n";
    }
    return 0;
}