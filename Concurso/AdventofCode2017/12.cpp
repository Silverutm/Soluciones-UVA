#include<bits/stdc++.h>
using namespace std;
#define tam 2005
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int rep[tam], cant[tam];

int encontrar_rep(int i)
{
    if (i == rep[i]) return i;
    return rep[i] = encontrar_rep(rep[i]);
}

void unir(int i, int j)
{
    int x, y;
    x = encontrar_rep(i);
    y = encontrar_rep(j);
    if (x == y) return;
    if (cant[x] > cant[y])
    {
        rep[y] = x;
        cant[x] += cant[y];
    }
    else 
    {
        rep[x] = y; 
        cant[y] += cant[x];
    }
}

int main()
{        
    //------------1------------   
    int i, u, v; 
    string s, bas;
    for (i=0; i<tam; ++i)
        rep[i] =i, cant[i] = 1;

    while(getline(cin, s))
    {
        stringstream ss(s);
        ss>>u>>bas;
        while(ss>>v)
            unir(u, v);
    }
    cout<<cant[ encontrar_rep(0) ]<<endl;

    //------------1------------  
    set <int> miset;
    for (i=0;i<2000; ++i)
        miset.insert(encontrar_rep(i));
    cout<<miset.size()<<endl;
    
    return 0;
}
