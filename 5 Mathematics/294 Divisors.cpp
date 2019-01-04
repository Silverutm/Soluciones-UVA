#include <bits/stdc++.h>
using namespace std;
//typedef long long ll;

int divisores(int n)
{    
    if (n == 1) return 1;
    int res = 0;
    int raiz = sqrt(n);
    for (int i = 1; i<= raiz; ++i)
        if (n%i==0) res += 2;

    if (n%raiz==0 and raiz * raiz== n) --res;
    return res;
}

int main()
{
    int t, l, u, res, c;
    int div, k;
    cin>>t;
    while(t--)
    {
        cin>>l>>u;
        div = -1; res = 0;
        c = l;
        while(l<=u)
        {
            if ( ( k = divisores(l) ) > div )
            {
                res = l;
                div = k;
            }
            ++l;
        }
        cout<<"Between "<<c<<" and "<<u<<", "<<res<<" has a maximum of "<<div<<" divisors.\n";
    }
    return 0;
}