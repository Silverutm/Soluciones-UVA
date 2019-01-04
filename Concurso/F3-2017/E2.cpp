#include <bits/stdc++.h>
#define f first
#define s second
#define mk make_pair
#define pb push_back
#define tam 100005
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;

#define mod 1000000007LL
#define mod2 1000000009LL
#define p 29
#define p2 31
int n, q, l, nl;
string cadenas[tam], consultas[tam];
map<pll,ll> mapa_jash;

ll tabla[150][tam], tabla2[150][tam], tab_p[tam], tab_p2[tam];
void llenar_Tabla()
{
    int i, j;
    tab_p[0] = 1;
    tab_p2[0] = 1;
    for ( j = 1; j < tam; ++j)
    {
        tab_p[j] = tab_p[j - 1] * p % mod;
        tab_p2[j] = tab_p2[j - 1] * p2 % mod2;
    }

    char letra;
    for ( i = 'a'; i <= 'z'; ++i)
    {
        letra = i - 'a' + 1;
        tabla[i][0] = letra;
        tabla2[i][0] = letra;
        for ( j = 1; j < tam; ++j)
        {
            tabla[i][j] = tab_p[j] * letra % mod;
            tabla2[i][j] = tab_p2[j] * letra % mod2;
        }
    }
}

pll sacar_jash(int i, string cadena[])
{
    ll r = 0, r2 = 0;    
    for (int k = 0; k < l; ++k)
    {
        r = (r + tabla[ cadena[i][k] ][nl-k]) % mod;
        r2 = (r2 + tabla2[ cadena[i][k] ][nl-k]) % mod2;
        //cout<<"hash "<<endl;
        //cout<<tabla[ cadena[i][k] ][nl-k]<<endl;
        //cout<<tabla2[ cadena[i][k] ][nl-k]<<endl;
        //cout<<r<<"  "<<r2<<endl;
    }    
    return pll{r,r2};
}

int main()
{
    //std::ios_base::sync_with_stdio (false);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i, j;   
    ll res, r, r2;
    pll el_jash;
    llenar_Tabla();
    //while(scanf("%d %d %d", &n, &q, &l)==3)
    while(cin>>n>>q>>l)
    {            
        nl = l - 1;
        mapa_jash.clear();
        for ( i = 0; i < n; ++i)
            cin>>cadenas[i];
        for ( i = 0; i < q; ++i)
            cin>>consultas[i];

        for ( i = 0; i < n; ++i)
        {
            el_jash = sacar_jash(i, cadenas);                    
            //cout<<"el el_jash  "<<cadenas[i]<<"  "<<el_jash.f<<"  "<<el_jash.s<<endl;
            for (int k = 0; k < l; ++k)
            {
                r = (el_jash.f - tabla[ cadenas[i][k] ][nl-k] + mod)%mod;
                r2 = (el_jash.s - tabla2[ cadenas[i][k] ][nl-k] + mod2)%mod2;
                //mapa_jash[pll{r,r2}]; 
                ++mapa_jash[pll{r,r2}];
                
                cout<<r<<"  "<<r2<<endl;
                //auto po = pll{r, r2};
                //++mapa_jash[po];
                //cout<<mapa_jash[pll{r,r2}]<<"   . "<<endl;
                //auto caca= mapa_jash[po];
            }
        }
        //cout<<endl;
        //for (auto e:mapa_jash)
            //cout<<e.f.f<<" "<<e.f.s<<" "<<e.s<<endl;
        for ( j = 0; j < q; ++j)
        {
            res = 0;
            el_jash = sacar_jash(j,consultas);
            for (int k = 0; k < l; ++k)
            {   
                r = (el_jash.f - tabla[ consultas[j][k] ][nl-k] + mod)%mod;
                r2 = (el_jash.s - tabla2[ consultas[j][k] ][nl-k] + mod2)%mod2;
                res += mapa_jash[pll{r, r2}];
                //auto po = pll{r, r2};
                //cout<<"po  "<<po.f<<" "<<po.s<<endl;
                //if (mapa_jash.find(po)!=mapa_jash.end())
                //    res += mapa_jash[po];
                //else cout<<"no esta prro\n";
                //cout<<r<<"  "<<r2<<endl;
            }
            //cout<<"res  "<<res<<"\n";
            cout<<res<<endl;
            //cout<<endl;
        }
    }
    return 0;
}





