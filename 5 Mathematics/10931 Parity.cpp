#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll z;
string res;
void binario(ll k)
{
    z = 0;
    bitset<60> mbs(k);
    int i = 59;
    while(not mbs[i]) --i;
    res = "";
    while (i>=0)
    {
        res.push_back( mbs[i] + '0' );
        if (mbs[i]) ++z;
        --i;
    }
    return ;
}

int main()
{
    ll k; int i = 0;
    while (cin>>k and k)
    {
        binario(k);
        cout<<"The parity of "<<res <<" is "<<z<<" (mod 2).\n";
    }
    return 0;
}