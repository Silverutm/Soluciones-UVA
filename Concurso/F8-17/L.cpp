#include <bits/stdc++.h>
using namespace std;
long long arr[20005];
int main()
{
    int n, i;
    cin>>n;
    for ( i=0; i<n;++i)
        cin>>arr[i];
    sort(arr, arr+n);

    for (i=2; i<n;++i)
        if (arr[i-2]+ arr[i-1] > arr[i])
        {
            cout<<"possible\n";
            return 0;
        }
    cout<<"impossible\n";
    return 0;
}