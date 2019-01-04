#include<bits/stdc++.h>
using namespace std;
#define tam 1205
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;

int main()
{
    int res = 0, x, j;
    vi v;
    set<vi> miset;
    map<vi, int> mapa;
    while (cin>>x) v.pb(x);
    
    //------------1------------
    /*do
    {
        miset.insert(v);
        j = max_element(v.begin(), v.end()) - v.begin();
        x = v[j];
        v[j] = 0;
        while (x--) ++v[(++j)%v.size()];
        ++res;
    }while (miset.find(v)==miset.end());    
    cout<<res<<endl;
    */


    //------------2------------
    do
    {
        mapa[v] = ++res;
        j = max_element(v.begin(), v.end()) - v.begin();
        x = v[j];
        v[j] = 0;
        while (x--) ++v[(++j)%v.size()];
        
    }while (mapa[v]==0);
    cout<<res - mapa[v] + 1<<endl;
    return 0;
}
