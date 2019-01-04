#include <bits/stdc++.h>
using namespace std;
#define tam 105
int mat[tam][tam], r, c;
int tabla[tam][tam];

int f(int i, int j)
{
    if (i<1 or i>r or j<1 or j>c) return 0;
    int &res = tabla[i][j];
    if (res!=-1) return res;
    res = 0;
    int m = mat[i][j];
    if (mat[i + 1][j] < m)
        res = max(res, f(i + 1, j));
    if (mat[i - 1][j] < m)
        res = max(res, f(i - 1, j));
    if (mat[i][j + 1] < m)
        res = max(res, f(i, j + 1));
    if (mat[i][j - 1] < m)
        res = max(res, f(i, j - 1));
    ++res;
    return res;
}

int main()
{
    int t, res, i ,j;
    string nombre;
    cin>>t;
    while(t--)
    {
        cin>>nombre>>r>>c;
        memset(tabla, -1, sizeof tabla);
        for(i=1; i<=r; ++i)
            mat[i][0] = mat[i][c+1] = tam;
        for(j=1; j<=c; ++j)
            mat[0][j] = mat[r+1][j] = tam;

        for(i=1; i<=r; ++i)
            for(j=1; j<=c; ++j)
                cin>>mat[i][j];
        
        res = -1;
        for(i=1; i<=r; ++i)
            for(j=1; j<=c; ++j)
                res = max(res, f(i, j));
        cout<<nombre<<": "<<res<<"\n";
    }
    return 0;
}