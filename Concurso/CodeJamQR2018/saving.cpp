#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define tam 35
ll arr[tam];
int main()
{
    int n_casos, d, n_shoots;
    ll danho_total, danho_tiro;
    string cadena;
    cin>>n_casos;        
    for (int caso = 1; caso<=n_casos; ++caso)
    {
        cout<<"Case #"<<caso<<": ";
        danho_total = 0LL;
        danho_tiro = 1;
        n_shoots = 0;
        memset(arr, 0LL, sizeof arr);

        cin>>d>>cadena;
        
        for (char &c:cadena)
            n_shoots += c == 'S';
        if (n_shoots > d )
        {
            cout<<"IMPOSSIBLE\n";
            continue ;
        }
        for (char &c:cadena)
        {
            if (c == 'C')
                danho_tiro <<= 1;
            else danho_total += danho_tiro;
        }
        if (d >= danho_total)
        {
            cout<<"0\n";
            continue ;
        }

        danho_tiro = 1;
        for (int i=0; i<cadena.size(); ++i)
        {
            auto c = cadena[i];
            if (c == 'C')
            {
                danho_tiro <<= 1;
                arr[i] = 0;
            }
            else arr[i] = danho_tiro;            
        }
        int contador = 0;
        for (int i=(int)cadena.size() - 2; i>= 0; --i)
        {
            if (cadena[i] == 'S') continue;
            for (int j= i + 1; j<cadena.size(); ++j)
            {
                if (cadena[j] == 'C') break;
                arr[j] >>= 1;
                danho_total -= arr[j];
                ++contador;
                if (d>= danho_total)
                {
                    cout<<contador<<"\n";
                    i = -5;
                    break;
                }
                swap(cadena[j-1], cadena[j]);
                swap(arr[j-1], arr[j]);
            }
        }


    }
    return 0;
}