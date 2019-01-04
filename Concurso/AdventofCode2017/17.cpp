#include<bits/stdc++.h>
using namespace std;
#define tam 20
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int main()
{        
    //------------1------------
    /*int salto = 312;
    list<int> lista(1);
    int pos = 0;    
    for (int i = 1; i<=2017; ++i)
    {
        pos = (pos + salto + 1)%lista.size();        
        auto otro = lista.begin();
        for (int j=0; j<pos; ++j)
            ++otro;
        lista.insert(otro, i);        
    }
    bool ya = false;
    for (auto e:lista)
    {
        if (ya) {cout<<e<<"\n"; break;}
        if (e==2017)
            ya = true;
    }*/

    //------------2------------
    int salto = 312;    
    int pos = 0;    
    int el_sig = -1;
    for (int i = 1; i<=50000000; ++i)
    {
        pos = (pos + salto + 1)%i;
        if (pos == 0) el_sig=i;        
    }
    cout<<el_sig<<"\n";    
    return 0;
}
