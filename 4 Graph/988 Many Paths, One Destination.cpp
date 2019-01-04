#include <bits/stdc++.h>
#define tam 100005
#define pb push_back
using namespace std;
typedef vector <int> vi;

//vi Lista[tam];
int p[tam];
int main()
{
    int i, n, a, k, j, res;
    bool ya = false;
    while(cin>>n)
    {        
        //for(i=0; i<n; ++i) Lista[i].clear();
        memset(p, 0, sizeof p);
        p[0] = 1;
        res = 0;
        for(i=0; i<n; ++i)
        {
            cin>>k;
            for(j=0; j<k; ++j)
            {
                cin>>a;
                p[a] += p[i];
            }
            if (not k) res += p[i];
        }
        if (ya) cout<<"\n"; ya = true;
        cout<<res<<"\n";

    }
    return 0;
}