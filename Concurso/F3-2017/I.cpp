#include <bits/stdc++.h>
#define f first
#define s second
#define mk make_pair
#define pb push_back
#define tam 7005
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;

string nombres[tam];
int frecuencia[tam], val[tam];
vector <ii> salida;
int main()
{
    int t, n, k;    
    scanf("%d", &t);
    while(t--)
    {
        salida.clear();
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; ++i)
        {
            cin>>nombres[i]>>frecuencia[i];
            val[i]=frecuencia[i];
            //cout<<nombres[i]<<"  "<<frecuencia[i]<<endl;
        }
//return 0;
        int maxi = *max_element(frecuencia, frecuencia+n);
        int m=maxi;
        //cout<<maxi<<endl;
        //return 0;
        do
        {
            for (int i = 0; i < n; ++i)
            {
                int x = val[i];
                while (x <= maxi)
                {
                    salida.push_back(ii{x,i});
                    x += frecuencia[i];
                    //cout<<"h"<<endl;
                }
                val[i] = x;
            }
            maxi += m;

        }while (salida.size()<k);
        sort(salida.begin(), salida.end());
        //return 0;
        for (int i = 0; i < k; ++i)
            cout<<salida[i].first<<" "<<nombres[salida[i].second]<<endl;
    }
    return 0;
}
