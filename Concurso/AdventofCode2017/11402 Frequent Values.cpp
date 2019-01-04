#include<bits/stdc++.h>
using namespace std;
#define tam 100005
#define pb push_back
typedef long long ll;
typedef pair <int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, a, b;
struct tres { ii izq, der, centro; };
tres arbol[tam<<2];
int arr[tam];

ii z[9];
int w;
tres combinar(tres x, tres y)
{
    if (x.izq.second==-1)
        return y;
    if (y.izq.second==-1)
        return x;

    z[0] = x.izq;
    w = 1;
    if (x.centro.second!=-1)
    {
        z[w] = x.centro;
        ++w;
        if (x.der.second!=-1)
        {
            z[w] = x.der;
            ++w;   
        }   
    }

    if (z[w - 1].first == y.izq.first)
        z[w - 1].second += y.izq.second;
    else
    {
        z[w] = y.izq;
        ++w;
    }
    
    if (y.centro.second!=-1)
    {
        z[w] = y.centro;
        ++w;
        if (y.der.second!=-1)
        {
            z[w] = y.der;
            ++w;   
        }   
    }
    tres res = tres{ii{-1,-1},ii{-1,-1}, ii{-1,-1}};
    res.izq = z[0];
    if (w==1)
        return res;
    
    res.centro = z[1];
    if (w==2)
        return res;

    for (int i=2; i<w-1; ++i)
        if (res.centro.second<z[i].second)
            res.centro = z[i];
    res.der = z[w-1];
    return res;




}
void imprime(int p, tres k)
{
    return ;
    cout<<p<<endl;
    cout<<k.izq.first<<"  "<<k.izq.second<<endl;
    cout<<k.centro.first<<"  "<<k.centro.second<<endl;
    cout<<k.der.first<<"  "<<k.der.second<<endl;
    cout<<endl;
}
void construir(int p, int i, int j)
{
    if (i == j)
    {
        arbol[p].izq = ii{arr[i], 1};
        arbol[p].centro = ii{1,-1};
        arbol[p].der = ii{1,-1};
        //imprime(p,arbol[p]);
        return ;
    }
    construir(p<<1, i, (i+j)/2);
    construir((p<<1) + 1, (i+j)/2 + 1, j);
    arbol[p] = combinar(arbol[p<<1], arbol[(p<<1)+1]);
    //imprime(p,arbol[p]);
}

tres consulta(int p, int i, int j)
{
    if (j<a or i>b)
        return tres{ii{-1,-1},ii{-1,-1}, ii{-1,-1}};
    if (i>=a and j<=b)
    {
        imprime(p,arbol[p]);
        return arbol[p];
    }
    auto hi = consulta(p<<1, i, (i+j)/2);
    auto hd = consulta((p<<1)+1, (i+j)/2 + 1, j);
    if (hi.izq.second==-1)
    {
        imprime(p, hd);
        return hd;
    }
    if (hd.izq.second==-1)
    {
        imprime(p, hi);
        return hi;
    }
    imprime(p,combinar(hi, hd));
    return combinar(hi, hd);
}

int main()
{    
    int q, i;
    while(scanf("%d", &n) and n)
    {
        scanf("%d", &q);
        for (i=1; i<=n; ++i)
            scanf("%d", &arr[i]);   
        construir(1, 1, n);
        while(q--)
        {
            scanf("%d %d", &a, &b);
            tres res = consulta(1, 1, n);
            ii r = res.izq;
            if (res.centro.second>r.second)
                r = res.centro;
            if (res.der.second>r.second)
                r = res.der;
            printf("%d\n", max(res.izq.second,max(res.centro.second, res.der.second)));
            //printf("%d\n", r.first);
        }
    }    
    return 0;
}
