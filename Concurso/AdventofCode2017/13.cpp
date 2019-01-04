#include<bits/stdc++.h>
using namespace std;
#define tam 90
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int arr[tam];
int main()
{        
    
    int i, val, res = 0;
    while(cin>>i>>val) arr[i] = val;

    //------------1------------   
    /*for (i=0; i<=88; ++i)
    {
        if (arr[i] == 0) continue;

        if ( i%((arr[i] - 1)<<1)==0 )
            res += i * arr[i];
    }
    cout<<res<<"\n";*/
    
    //------------2------------   
    bool atrapado = true;
    int k = 0;
    while(atrapado)
    {
        ++k;
        atrapado = false;
        for (i=0; i<=88 and not atrapado; ++i)
        {
            if (arr[i] == 0) continue;

            if ( (i + k)%((arr[i] - 1)<<1)==0 )
                atrapado = true;
        }        
    }
    cout<<k<<"\n";
    return 0;
}
