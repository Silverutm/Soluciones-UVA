#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, i;
    bool ya;
    while(cin>>n and n)
    {
        ya = false;
        for (i=0; i<n; ++i)
        {
            cin>>a;            
            if (a)
            {
                if (ya) cout<<" ";
                cout<<a;
                ya = true;
            }
                
        }
        if (not ya) cout<<0;
        cout<<"\n";
    }
    return 0;
}