#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll k; int i = 0;
    while (cin>>k and k)    
        cout<<"Case "<< ++i <<": "<<(ll)ceil( (3.0 + sqrt(9+8*k) )/2 )<<"\n";    
    return 0;
}