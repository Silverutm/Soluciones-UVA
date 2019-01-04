#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair<int, double> id;
#define tam 1005


map<string, int> mapa;
int raiz, cant;

vi Lista[tam];
double velos[tam];
id suma_de_hijos[tam];
id tabla[tam];

id g(int u)
{
    id &res = tabla[u];
    //if (res.first != -1) return res;
    for (int v:Lista[u])
    {
        g(v);
        suma_de_hijos[u].first += tabla[v].first;
        suma_de_hijos[u].second += tabla[v].second;
    }
    res = suma_de_hijos[u];
    for (int v:Lista[u])
    {        
        id z( suma_de_hijos[u].first - tabla[v].first + 1 + suma_de_hijos[v].first,
            suma_de_hijos[u].second - tabla[v].second + min(velos[u], velos[v]) + suma_de_hijos[v].second);
        res = max(res, z);
    }
    return res;
}

int main()
{  
    int n, i, f;
    string per, sup;
    double vel;
    cin>>n;
    while (n--)
    {
        cin>>per>>vel>>sup;
        
        if (mapa[per])
            i = mapa[per];
        else i = mapa[per] = ++cant;

        velos[i] = vel;

        if (sup == "CEO") { raiz = i; continue; }

        if (mapa[sup])
            f = mapa[sup];
        else f = mapa[sup] = ++cant;

        Lista[f].push_back(i);
    }

    /*for (int i=1; i<=cant; ++i)
    {
        cout<<i<<endl;
        for (auto v:Lista[i])
            cout<<v<<" ";
        cout<<endl;
    }
    return 0;*/
    for (int i=0; i<=cant+1; ++i)
        tabla[i].first = -1;
    auto z = g(raiz);
    printf("%d %lf\n", z.first, z.second / z.first);
    //cout<<g(raiz).first<<" "<<g(raiz).second;
}