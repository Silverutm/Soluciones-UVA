#include <bits/stdc++.h>
using namespace std;
int arreglo[10000];
int main()
{
    int z, i, m, l, j, caso=0;
    while (cin>>z>>i>>m>>l and m)    
    {        
        for (j = 0; j<m; ++j) arreglo[j] = 0;
        j = 1;
        while (not arreglo[l])
        {
            arreglo[l] = j;
            l = ( z * l + i ) % m;
            ++j;
        }
        cout<<"Case "<<++caso<<": "<<j - arreglo[l]<<"\n";
    }
    return 0;
}