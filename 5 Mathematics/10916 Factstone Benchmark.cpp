#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tam 1000005
double fact[tam];
int main()
{
    fact[0] = 0.0;
    for (int i=1; i<tam; ++i)
        fact[i] = fact[i-1] + log2( double(i) );
    
    int n, x;
    while (cin>>n and n)
    {        
        n = (n - 1960)/10;
        double pot = 1<<(n+2);
        x = upper_bound(fact, fact + tam, pot) - fact - 1;
        cout<<x<<"\n";
    }
    return 0;
}