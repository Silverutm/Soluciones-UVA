#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define tam 1000005
typedef vector <int> vi;

int grado[tam], ini[tam], fin[tam];
int degreeOfArray(vi arr)
{
    int i = 1;
    for (int e:arr) 
    {
        ++grado[e];
        if (not ini[e]) ini[e] = i;
        fin[e] = i;
        ++i;
    }
    
    int j = max_element(grado, grado+tam) - grado;
    int res = tam;
    for (int i=1; i<tam; ++i)
        if (grado[i] == grado[j])
            res = min(res, fin[i] - ini[i] );
    return res + 1;
}

int main()
{
    
    int n, a;
    vi v;
    cin>>n;
    while(n--)
    {
        cin>>a;
        v.pb(a);        
    }
    cout<<degreeOfArray(v)<<endl;
}

