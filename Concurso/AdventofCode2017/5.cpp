#include<bits/stdc++.h>
using namespace std;
#define tam 1205
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;

int arr[tam];
int main()
{
    int res = 0, n=0, ins = 1, salto;
    while(cin>>arr[++n]);
    --n;
    
    while (ins>0 and ins<=n)
    {
        //------------1------------
        //ins += arr[ins]++;        
        
        //------------2------------
        salto = arr[ins];
        if (salto>=3) --arr[ins];
        else ++arr[ins];
        ins += salto;

        ++res;
    }    
    cout<<res<<endl;
    return 0;
}
