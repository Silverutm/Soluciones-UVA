#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tam 1005

ll arr[tam];
int main()
{
    int t, n, i;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (i=0; i<n; ++i)
            scanf("%lld", &arr[i]);
        int x = arr[0];
        for (i=1; i<n-1; ++i)
            if (x + i != arr[i])
            {
                printf("%d\n", i+1);
                break;
            }

    }
    return 0;
}