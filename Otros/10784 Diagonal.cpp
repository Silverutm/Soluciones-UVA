#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll k;
    while (cin>>k and k)
    {
        cout<<(ll)ceil( (3.0 + sqrt(9+8*k) )/2 )<<"\n";
    }
    return 0;
}