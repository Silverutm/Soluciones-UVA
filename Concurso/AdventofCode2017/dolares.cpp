#include<bits/stdc++.h>
using namespace std;
#define tam 55
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
map<int,map<int, int>> tabla[tam], visi[tam]; //dia, dolares,pesos
int arr[tam], n;

int f(int dia, int dolares, int pesos)
{
    int &ya = visi[dia][dolares][pesos];
    int &res = tabla[dia][dolares][pesos];
    if (ya) return res;
    ya = 1;

    if (dia>n) return pesos;

    //si es mayor al anterior vendes o nada
    //si es menor al anterior compras o nada

    if (arr[dia]>arr[dia-1])
    {
        if (arr[dia+1]>=arr[dia])
            return res = f(dia +1, dolares, pesos);
        return res = max (f(dia +1, dolares, pesos),
                    f(dia + 1, 0, pesos + dolares * arr[dia] )              
                );
    }
        
    if (arr[dia]<arr[dia-1])
    {
        if (arr[dia+1]<=arr[dia])
            return res = f(dia +1, dolares, pesos);
        return res = max (f(dia +1, dolares, pesos),                        
                        f(dia +1, dolares + pesos/arr[dia], pesos%arr[dia] )              
                    );
    }
        
    
    return res = f(dia +1, dolares, pesos);

    return res = max( f(dia +1, dolares, pesos),
                 max( f(dia + 1, 0, pesos + dolares * arr[dia] ), 
                      f(dia +1, dolares + pesos/arr[dia], pesos%arr[dia] )  
    ));
}

int main()
{
    int m;
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
        cin>>arr[i];
    arr[0] = 100000000;
    cout<<f(1, 0, m) - m<<endl;
    
    return 0;
}
