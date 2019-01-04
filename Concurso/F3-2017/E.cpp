#include <bits/stdc++.h>
#define f first
#define s second
#define mk make_pair
#define pb push_back
#define tam 500005
using namespace std;
typedef long long ll;
typedef pair <int, int> ii;
typedef pair<ll, ll> pll;
typedef vector <int> vi;
typedef vector <vi> vvi;

string cadenas[tam], consultas[tam];
int main()
{
    std::ios_base::sync_with_stdio (false);
    int n, q, l, err;   
    ll res;
    //while(scanf("%d %d %d", &n, &q, &l)==3)
    while(cin>>n>>q>>l)
    {
        
        //if (n>100000 or q>100000 or l>100000)
        //	for(;;);
        for (int i = 0; i < n; ++i)
            cin>>cadenas[i];
        for (int i = 0; i < q; ++i)
            cin>>consultas[i];

        for (int j = 0; j < q; ++j)
        {
            res = 0;
            for (int i = 0; i < n; ++i)
            {
                err=0;
                for (int k = 0; err<2 and k < l; ++k)
                    if (cadenas[i][k]!=consultas[j][k]) ++err;
                if (err==0) res+=l;
                else if (err==1 and l!=1) ++res;
            }
            //printf("hola\n");
            //printf("%lld\n", res);
            cout<<res<<"\n";
        }
    }
    return 0;
}





