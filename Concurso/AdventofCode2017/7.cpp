#include<bits/stdc++.h>
using namespace std;
#define tam 1505
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vii Lista[tam];
int pesos[tam];
int chido=0;
int buscar(int u)
{    
    int res = 0;
    for (auto &v:Lista[u])
    {
        res += (v.second = buscar(v.first) );
    }
    if (Lista[u].size()>2 and chido==0)
    {        
        int x =Lista[u][0].second;        
        bool aqui = false;
        int i=0;
        for (auto &v:Lista[u])
        {
            if (v.second != x and chido==0)
            {
                if (i==1)
                {
                    if (Lista[u][2].second!=x) //el 0 es el malo
                    {
                        chido = pesos[ Lista[u][0].first ] - ( x - Lista[u][1].second );                        
                    }
                    else //el 1 es el malo
                    {                        
                        chido = pesos[ Lista[u][1].first ] - ( Lista[u][1].second - Lista[u][0].second );                        
                    }
                }
                else //el i es el malo
                {                    
                    chido = pesos[ Lista[u][i].first ] - ( Lista[u][i].second - Lista[u][0].second );                    
                }
                


            }
            ++i;
        }
    }    
    return res + pesos[u];
}

int main()
{
    int n=0, i;
    string s, nombre, peso, arriba, lista[tam];    
    set<string> tiene_papa;    
    //xegshds

    //------------1------------
    /*while(getline(cin, s))
    {
        stringstream ss(s);
        ss>>nombre>>peso;
        lista[n++] = nombre;
        if (ss>>arriba)
        while(ss>>arriba)
        {
            if (arriba[arriba.size()-1]==',')
                arriba.pop_back();
            tiene_papa.insert(arriba);
        }        
    }
    for (i=0; i<n; ++i)
        if (tiene_papa.find(lista[i])==tiene_papa.end() )
            cout<<lista[i]<<endl;  */

    //------------2------------
    map<string, int> mapa;    
        
    while(getline(cin, s))
    {
        stringstream ss(s);
        ss>>nombre>>peso;
        if (not mapa[nombre])
            mapa[nombre] = ++n;

        peso = peso.substr( 1, peso.size() - 2);
        stringstream ss2(peso);
        ss2>>pesos[ mapa[nombre] ];
        if (ss>>arriba)
        while(ss>>arriba)
        {
            if (arriba[arriba.size()-1]==',')
                arriba.pop_back();
            
            if (not mapa[arriba])
                mapa[arriba] = ++n;
            Lista[ mapa[nombre] ].pb( ii{mapa[arriba],0} );
        }        
    }
    //buscar(mapa["tknk"]);
    buscar(mapa["xegshds"]);
    cout<<chido<<endl;
    return 0;
}
