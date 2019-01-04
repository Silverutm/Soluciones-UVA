#include <bits/stdc++.h>
using namespace std;
#define tam 100005
int arr[tam], arr1[tam], arr2[tam];
int main()
{
    int t, caso, n, i, j, k;
    bool ok;
    cin>>t;
    for (caso = 1; caso<=t; ++caso)
    {
        cout<<"Case #"<<caso<<": ";        
        cin>>n;
        j = 0; k = 0;
        ok = true;
        for ( i= 0; i<n; ++i)
        {
            cin>>arr[i];
            /*if (i&1)
                arr2[k++] = arr[i];
            else arr1[j++] = arr[i];*/
            (i&1 ? arr2[k++]:arr1[j++]) = arr[i];            
        }
        sort(arr, arr +n);
        sort(arr1, arr1 + j);
        sort(arr2, arr2 + k);
        j = 0; k = 0;
        for ( i= 0; i<n; ++i)
        {
            if (i&1)
            {
                if (arr2[k++] != arr[i])
                {
                    cout<<i<<"\n";
                    ok = false;
                    break;
                }
            }
            else 
            {
                if (arr1[j++] != arr[i])
                {
                    cout<<i<<"\n";
                    ok = false;
                    break;
                }
            }
        }
        if (ok)               
            cout<<"OK\n";
    }
    return 0;
}