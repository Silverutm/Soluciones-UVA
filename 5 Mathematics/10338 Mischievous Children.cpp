#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fact[23];

int main()
{
    fact[0] = 1;
    for(int i=1;i<21; ++i)
        fact[i] = fact[i-1]*i;
    int t, letras[500];
    ll res;
    string cad;
    cin>>t;
    for (int caso=1; caso<=t; ++caso)
    {
        memset(letras, 0, sizeof letras);
        cin>>cad;
        for (char c:cad) ++letras[c];
        res = fact[cad.size()];
        for (int i='A'; i<='Z'; ++i)
            res /=fact[ letras[i] ];
        cout<<"Data set "<< caso <<": "<< res <<"\n";
        //cout<<res<<"\n";
    }
    return 0;
}