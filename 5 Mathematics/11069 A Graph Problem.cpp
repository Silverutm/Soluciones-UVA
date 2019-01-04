#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[80];
int main()
{
    f[1] = 1; f[2] = 2; f[3] = 2;
    for (int i=4;i<77; ++i)
        f[i] = f[i-2] + f[i-3];
    int n;
    while (cin>>n)
        cout<<f[n]<<"\n";
    return 0;
}