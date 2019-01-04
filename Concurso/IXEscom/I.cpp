#include <bits/stdc++.h>
using namespace std;
#define tam 100005
typedef long long ll;
ll arr[tam], suma[tam];
int main()
{
    ll n, x;
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>arr[i];
    for (int i=1; i<=n; ++i)
    {
        if (suma[i-1]>0)
            x = suma[i-1] + arr[i];
        else x = arr[i];
        suma[i] = max(arr[i], x);
    }
    cout<<*max_element(suma+1, suma+n+1)<<"\n";
    return 0;
}